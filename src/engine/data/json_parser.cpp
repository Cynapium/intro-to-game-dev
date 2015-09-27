#include "json_parser.h"
#include "../memory/default_allocator.h"
#include "../containers/dynamic_array.h"
#include "../containers/map.h"
#include "json_array.h"
#include "json_object.h"
#include <exception>
#include <iostream>

namespace StevensDev
{
namespace sgdd
{
//static sgdm::IAllocator<JsonEntity*>*       d_allocator;
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
            return new TokenString( STRING, "test" );

            // PRIMITIVE
        default:
            return new TokenBool( BOOLEAN, true );
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

JsonEntity*
JsonParser::parseString()
{
    std::cout << "\tparseString starting at " << d_index << std::endl;

    int         i_start = d_index + 1;

    // Browse until we find another "
    while ( d_index < d_json.size() && d_json[d_index] != '"' )
        d_index++;

    std::string s = d_json.substr( i_start, d_index - i_start );

    return new JsonString ( s );
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
JsonParser::fromString( const std::string& json)//, sgdm::IAllocator* alloc = 0 )
{
    // Initialize variables
    /*
    if ( alloc )
        d_allocator = alloc;
    else
        d_allocator = new sgdm::DefaultAllocator;
        */
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
