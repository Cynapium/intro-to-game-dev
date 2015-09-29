// json_parser.cpp

#include "json_parser.h"

#include "data/json_array.h"
#include "data/json_object.h"
#include "memory/default_allocator.h"
#include "containers/dynamic_array.h"
#include "containers/map.h"
#include "invalid_json.h"
#include <cstdlib>
#include <exception>
#include <iostream>

namespace StevensDev
{
namespace sgdd
{

// Static variables from JsonParser class
sgdm::IAllocator<JsonEntity*>*  JsonParser::d_allocator = 0;
std::string                     JsonParser::d_json = "";
int                             JsonParser::d_index = -1;

//
// PRIVATE MEMBER FUNCTIONS
//

Token*
JsonParser::token()
{
    d_index++;

    if ( d_index >= d_json.size() )
    {
        return nullptr;
    }

    switch ( d_json[d_index] )
    {
        // SPACES AND NEWLINES (We skip them)
        case ' ':
        case '\r':
        case '\n':
            return token();

        // OBJECT
        case '{':
            return new Token( OPEN_BRACE );
        case '}':
            return new Token( CLOSE_BRACE );

            // PUNCTUATION INSIDE OBJECT
        case ',':
            return new Token( COMMA );
        case ':':
            return new Token( COLON );

            // ARRAY
        case '[':
            return new Token( OPEN_BRACKET );
        case ']':
            return new Token( CLOSE_BRACKET );

            // STRING
        case '"':
        case '\'':
            return parseString();

        // BOOLEAN
        case 't':
        case 'f':
            return parseBool();

        // NULL
        case 'n':
            return parseNull();

        // INTEGER or DOUBLE
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '-':
            return parseNumber();

            // PRIMITIVE
        default:
            throw InvalidJsonException( "Unknown token", d_json[d_index] );
    }
}

Token*
JsonParser::parseNull()
{
    Token*   token = nullptr;

    if ( d_json.substr( d_index, 4 ) == "null" )
    {
        token = new Token( NULLPTR );
        d_index += 4;
    }
    else
    {
        throw std::invalid_argument( "parseNull" ); //TODO
    }

    return token;
}

Token*
JsonParser::parseBool()
{
    TokenBool*   token = nullptr;

    if ( d_json.substr( d_index, 5 ) == "false" )
    {
        token = new TokenBool( BOOLEAN, false );
        d_index += 4;
    }
    else if ( d_json.substr( d_index, 4 ) == "true" )
    {
        token = new TokenBool(BOOLEAN, true );
        d_index += 3;
    }
    else
    {
        throw std::invalid_argument( "parseBool" ); //TODO
    }

    return token;
}

Token*
JsonParser::parseNumber()
{
    const char      *numbers = "0123456789";
    int              i_start = d_index++;
    size_t           i = d_json.find_first_not_of( numbers, d_index );
    bool             isFloat = false;

    if ( d_json[i] == '.' )
    {
        isFloat = true;
        i = d_json.find_first_not_of( numbers, i + 1 );
    }

    std::string      nb = d_json.substr( i_start, i - i_start );

    d_index = i - 1;

    if ( isFloat )
    {
        return new TokenDouble( DOUBLE, atof( nb.c_str() ) );
    }
    else
    {
        return new TokenInt( INTEGER, atoi( nb.c_str() ) );
    }
}

Token*
JsonParser::parseString()
{
    int         i_start = ++d_index;

    // Browse until we find another "
    while ( d_index < d_json.size() &&
            d_json[d_index] != '"' && d_json[d_index] != '\'')
    {
        d_index++;
    }

    std::string s = d_json.substr( i_start, d_index - i_start );

    return new TokenString ( STRING, s );
}


JsonArray*
JsonParser::createArray()
{
    ArrayJEntity        array;
    Token               expect( NULLPTR );

    while ( true )
    {
        Token*          t = token();

        if ( t == nullptr )
        {
            throw InvalidJsonException( "End of file", "" );
        }

        // We check if the token is the one we expected
        if ( ( expect.type() != NULLPTR && t->type() != expect.type() &&
               t->type() != CLOSE_BRACKET ) ||
               ( expect.type() != COMMA && t->type() == CLOSE_BRACKET ) )
        {
            std::string err = "createArray: Invalid token \"";
            err += t->typeStr();
            err += "\" when expected \"";
            err += expect.typeStr();
            err += "\"";
            throw std::invalid_argument( err );
        }

        switch ( t->type() )
        {
            case COMMA:
                expect.setType( NULLPTR );
                break;

            // Possible values
            case STRING:
                array.push( createString( t ) );
                expect.setType( COMMA );
                break;

            case INTEGER:
                array.push( createInt( t ) );
                expect.setType( COMMA );
                break;

            case DOUBLE:
                array.push( createDouble( t ) );
                expect.setType( COMMA );
                break;

            case BOOLEAN:
                array.push( createBool( t ) );
                expect.setType( COMMA );
                break;

            // New array
            case OPEN_BRACKET:
                array.push( createArray() );
                expect.setType( COMMA );
                break;

            // New object
            case OPEN_BRACE:
                array.push( createObject() );
                expect.setType( COMMA );
                break;

            // End of the array
            case CLOSE_BRACKET:
                return new JsonArray( array );

            // Everything else is an error
            default:
                std::string err = "createArray: Invalid token \"";
                err += t->typeStr();
                err += "\"";
                throw std::invalid_argument( err );
        }
    }
}

JsonObject*
JsonParser::createObject()
{
    MapJEntity          object;
    Token               expect( STRING );

    // Initialization of a new attribute
    std::string     key;
    JsonEntity*     value = nullptr;

    while ( true )
    {
        Token*          t = token();

        // We check if the token is the one we expected
        if ( ( expect.type() != NULLPTR && t->type() != expect.type() &&
               t->type() != CLOSE_BRACE ) ||
               ( expect.type() != COMMA && t->type() == CLOSE_BRACE ) )
        {
            std::string err = "createArray: Invalid token \"";
            err += t->typeStr();
            err += "\" when expected \"";
            err += expect.typeStr();
            err += "\"";
            throw std::invalid_argument( err );
        }

        switch ( t->type() )
        {
            case COLON:
                expect.setType( NULLPTR );
                break;

            case COMMA:
                object[key] = value;
                expect.setType( STRING );
                break;

            case STRING:
                // If we expect a STRING then it's an identifier
                if ( expect.type() == STRING )
                {
                    key = ( ( TokenString* ) t )->value();
                    expect.setType( COLON );
                }
                // If we didn't explicitly expected a STRING then it's a value
                else
                {
                    value = createString( t );
                    expect.setType( COMMA );
                }
                break;

            // Possible values

            case INTEGER:
                value = createInt( t );
                expect.setType( COMMA );
                break;

            case DOUBLE:
                value = createDouble( t );
                expect.setType( COMMA );
                break;

            case BOOLEAN:
                value = createBool( t );
                expect.setType( COMMA );
                break;

            case OPEN_BRACKET:
                value = createArray();
                expect.setType( COMMA );
                break;

            case OPEN_BRACE:
                value = createObject();
                expect.setType( COMMA );
                break;

            // End of the Object definition
            case CLOSE_BRACE:
                object[key] = value;
                return new JsonObject( object );

            // Error
            default:
                std::string err = "createArray: Invalid token \"";
                err += t->typeStr();
                err += "\"";
                throw std::invalid_argument( err );
        }
    }
}
JsonInt*
JsonParser::createInt( Token* token )
{
    TokenInt*        t = ( TokenInt* ) token;

    return new JsonInt( t->value() );
}

JsonBool*
JsonParser::createBool( Token* token )
{
    TokenBool*        t = ( TokenBool* ) token;

    return new JsonBool( t->value() );
}

JsonDouble*
JsonParser::createDouble( Token* token )
{
    TokenDouble*        t = ( TokenDouble* ) token;

    return new JsonDouble( t->value() );
}

JsonString*
JsonParser::createString( Token* token )
{
    TokenString*        t = ( TokenString* ) token;

    return new JsonString( t->value() );
}

// FIXME
// The allocator is not used in this class.
// How can we use the allocator on JsonEntity without truncating the datas in
// the child classes? (ie. JsonPrimitive in a JsonEntity is going to lose
// information)
// This current version obviouly do not work because we return a JsonEntity**
// instead of a JsonEntity*
//JsonEntity*
//JsonParser::newString( Token* token )
//{
//    TokenString*        t = ( TokenString* ) token;
//    JsonEntity*         entity = new JsonString( t->value() );
//    JsonEntity**        memory = d_allocator->get( 1 );
//
//    d_allocator->construct( memory, entity );
//
//    delete              entity;
//
//    return memory;
//}

//
// PUBLIC MEMBER FUNCTIONS
//

JsonEntity*
JsonParser::fromString( const std::string& json,
                        sgdm::IAllocator<JsonEntity*>* alloc )
{
    // Initialize variables
    if ( alloc == 0 )
    {
        d_allocator = new sgdm::DefaultAllocator<JsonEntity*>();
    }
    else
    {
        d_allocator = alloc;
    }
    d_json = json;
    d_index = -1;

    // Read first token
    Token       *t = token();
    if ( t->type() == OPEN_BRACE )
    {
        // First token is {
        return createObject();
    }
    else if ( t->type() == OPEN_BRACKET )
    {
        // First token is [
        return createArray();
    }
    else
    {
        // First token is invalid
        std::string err = "createArray: Invalid token \"";
        err += t->typeStr();
        err += "\" at index 0";
        throw std::invalid_argument( err );
    }

    return nullptr;
}



} // End sgdd namespace
} // End StevensDev namespace

