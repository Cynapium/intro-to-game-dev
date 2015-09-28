// json_parser.cpp

#include "json_parser.h"
#include "json_array.h"
#include "json_object.h"
#include "../memory/default_allocator.h"
#include "../containers/dynamic_array.h"
#include "../containers/map.h"
#include <cstdlib>
#include <exception>
#include <iostream>

namespace StevensDev
{
namespace sgdd
{

// Static variables from JsonParser class
std::string             JsonParser::d_json = "";
int                     JsonParser::d_index = -1;

//
// PRIVATE MEMBER FUNCTIONS
//

Token*
JsonParser::token()
{
    d_index++;
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
            throw std::exception();
    }
}

JsonEntity*
JsonParser::parseArray()
{
    ArrayJEntity        array;
    Token               expect( NULLPTR );

    while ( true )
    {
        Token*          t = token();

        // We check if the token is the one we expected
        if ( ( expect.type != NULLPTR && t->type != expect.type &&
               t->type != CLOSE_BRACKET ) ||
               ( expect.type != COMMA && t->type == CLOSE_BRACKET ) )
        {
            std::string err = "parseArray: Invalid token \"";
            err += t->typeStr();
            err += "\" when expected \"";
            err += expect.typeStr();
            err += "\"";
            throw std::invalid_argument( err );
        }

        switch ( t->type )
        {
            case COMMA:
                expect.type = NULLPTR;
                break;

            // Possible values
            case STRING:
                array.push( asString( t ) );
                expect.type = COMMA;
                break;

            case INTEGER:
                array.push( asInt( t ) );
                expect.type = COMMA;
                break;

            case DOUBLE:
                array.push( asDouble( t ) );
                expect.type = COMMA;
                break;

            case BOOLEAN:
                array.push( asBool( t ) );
                expect.type = COMMA;
                break;

            // New array
            case OPEN_BRACKET:
                array.push( parseArray() );
                expect.type = COMMA;
                break;

            // New object
            case OPEN_BRACE:
                array.push( parseObject() );
                expect.type = COMMA;
                break;

            // End of the array
            case CLOSE_BRACKET:
                return new JsonArray( array );

            // Everything else is an error
            default:
                std::string err = "parseArray: Invalid token \"";
                err += t->typeStr();
                err += "\"";
                throw std::invalid_argument( err );
        }
    }
}

JsonEntity*
JsonParser::parseObject()
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
        if ( ( expect.type != NULLPTR && t->type != expect.type &&
               t->type != CLOSE_BRACE ) ||
               ( expect.type != COMMA && t->type == CLOSE_BRACE ) )
        {
            std::string err = "parseArray: Invalid token \"";
            err += t->typeStr();
            err += "\" when expected \"";
            err += expect.typeStr();
            err += "\"";
            throw std::invalid_argument( err );
        }

        switch ( t->type )
        {
            case COLON:
                expect.type = NULLPTR;
                break;

            case COMMA:
                object[key] = value;
                expect.type = STRING;
                break;

            case STRING:
                // If we expect a STRING then it's an identifier
                if ( expect.type == STRING )
                {
                    key = ( ( TokenString* ) t )->value;
                    expect.type = COLON;
                }
                // If we didn't explicitly expected a STRING then it's a value
                else
                {
                    value = asString( t );
                    expect.type = COMMA;
                }
                break;

            // Possible values

            case INTEGER:
                value = asInt( t );
                expect.type = COMMA;
                break;

            case DOUBLE:
                value = asDouble( t );
                expect.type = COMMA;
                break;

            case BOOLEAN:
                value = asBool( t );
                expect.type = COMMA;
                break;

            case OPEN_BRACKET:
                value = parseArray();
                expect.type = COMMA;
                break;

            case OPEN_BRACE:
                value = parseObject();
                expect.type = COMMA;
                break;

            // End of the Object definition
            case CLOSE_BRACE:
                object[key] = value;
                return new JsonObject( object );

            // Error
            default:
                std::string err = "parseArray: Invalid token \"";
                err += t->typeStr();
                err += "\"";
                throw std::invalid_argument( err );
        }
    }
}

TokenString*
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

TokenBool*
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

JsonString*
JsonParser::asString( Token* token )
{
    TokenString*        t = ( TokenString* ) token;

    return new JsonString( t->value );
}

JsonInt*
JsonParser::asInt( Token* token )
{
    TokenInt*        t = ( TokenInt* ) token;

    return new JsonInt( t->value );
}

JsonDouble*
JsonParser::asDouble( Token* token )
{
    TokenDouble*        t = ( TokenDouble* ) token;

    return new JsonDouble( t->value );
}

JsonBool*
JsonParser::asBool( Token* token )
{
    TokenBool*        t = ( TokenBool* ) token;

    return new JsonBool( t->value );
}

//
// PUBLIC MEMBER FUNCTIONS
//

JsonEntity*
JsonParser::fromString( const std::string& json)
{
    // Initialize variables
    d_json = json;
    d_index = -1;

    // Read first token
    Token       *t = token();
    if ( t->type == OPEN_BRACE )
    {
        // First token is {
        return parseObject();
    }
    else if ( t->type == OPEN_BRACKET )
    {
        // First token is [
        return parseArray();
    }
    else
    {
        // First token is invalid
        std::string err = "parseArray: Invalid token \"";
        err += t->typeStr();
        err += "\" at index 0";
        throw std::invalid_argument( err );
    }

    return nullptr;
}



} // End sgdd namespace
} // End StevensDev namespace

