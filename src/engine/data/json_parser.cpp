#include "json_parser.h"
#include "../memory/default_allocator.h"
#include "../containers/dynamic_array.h"
#include "../containers/map.h"
#include "json_array.h"
#include "json_object.h"
#include <exception>
#include <iostream>
#include <cstdlib>

namespace StevensDev
{
namespace sgdd
{
std::string             JsonParser::d_json = "";
int                     JsonParser::d_index = -1;

//
// PRIVATE MEMBER FUNCTIONS
//

Token*
JsonParser::token()
{
    d_index++;
    std::cout << "\tCheck token \"" << d_json[d_index] << "\" at " << d_index
        << std::endl;
    switch ( d_json[d_index] )
    {
        // OBJECT
        case '{':
            return new Token( OPEN_BRACE );
        case '}':
            return new Token( CLOSE_BRACE );

            // PUNCTUATION INSIDE OBJECT
        case ' ':
            return new Token( SPACE );
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
    sgdc::DynamicArray<JsonEntity*> array;//( d_allocator );

    while ( true )
    {
        Token*              t = token();

        switch ( t->type )
        {
            case COMMA:
            case SPACE:
                break;

            case STRING:
                array.push( asString( t ) );
                break;

            case INTEGER:
                array.push( asInt( t ) );
                break;

            case DOUBLE:
                array.push( asDouble( t ) );
                break;

            case BOOLEAN:
                array.push( asBool( t ) );
                break;

            case CLOSE_BRACKET:
                return new JsonArray( array );

            default:
                std::string err = "parseArray: Invalid token \"";
                err += t->typeStr();
                err += "\"";
                throw std::invalid_argument( err );
        }
    }
}

/*
JsonObject*
JsonParser::parseObject()
{
    while ( true )
    {
        Token       *t = token();

        switch ( t.type )
        {
            case 
        }
    }
}*/

TokenString*
JsonParser::parseString()
{
    std::cout << "\tparseString starting at " << d_index << std::endl;

    int         i_start = ++d_index;

    // Browse until we find another "
    while ( d_index < d_json.size() &&
            d_json[d_index] != '"' && d_json[d_index] != '\'')
    {
        d_index++;
    }

    std::string s = d_json.substr( i_start, d_index - i_start );

    std::cout << "\tparseString stopped at " << d_index << ": " << s << std::endl;

    return new TokenString ( STRING, s );
}

Token*
JsonParser::parseNumber()
{
    const char      *numbers = "0123456789";
    int              i_start = d_index++;
    size_t           i = d_json.find_first_not_of( numbers, d_index );
    bool             isFloat = false;

    std::cout << "INDEX IS NOW " << i << std::endl;
    if ( d_json[i] == '.' )
    {
        isFloat = true;
        i = d_json.find_first_not_of( numbers, i + 1 );
        std::cout << "INDEX IS NOW " << i << std::endl;
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
        d_index += 5;
    }
    else if ( d_json.substr( d_index, 4 ) == "true" )
    {
        token = new TokenBool(BOOLEAN, true );
        d_index += 4;
    }
    else
    {
        throw std::invalid_argument( "parseBool" ); //TODO
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

    std::cout << "START PARSING STRING: " << json << std::endl;

    // Read first token
    Token       *t = token();
    if ( t->type == OPEN_BRACE )
    {
        // First token is {
        //return parseObject();
        ;
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

