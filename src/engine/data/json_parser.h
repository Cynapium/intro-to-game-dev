// json_parser.cpp

#ifndef INCLUDED_JSON_PARSER
# define INCLUDED_JSON_PARSER

#include "memory/iallocator.h"
#include "data/json_array.h"
#include "data/json_entity.h"
#include "data/json_object.h"
#include "data/json_primitive.h"
#include "data/token.h"
#include "data/token_primitive.h"
#include <string>

namespace StevensDev
{
namespace sgdd
{

class JsonParser
{
  private:

    static sgdm::IAllocator<JsonEntity*>*   d_allocator;
      // Allocator used to allocate memory

    static std::string                      d_json;
      // String json to parse

    static int                              d_index;
      // Index of the lexer inside the json string


    // MEMBER FUNCTIONS

    static Token*                           token();
      // Analyze the json string and return the next token (lexer)

    static Token*                           parseNull();
      // Parse a null token

    static Token*                           parseBool();
      // Parse a bool token

    static Token*                           parseNumber();
      // Parse a integer or a double token

    static Token*                           parseString();
      // Parse a string token


    static JsonArray*                       createArray();
      // Create a JsonArray from the json string

    static JsonObject*                      createObject();
      // Create a JsonObject from the json string

    static JsonInt*                         createInt( Token* t );
      // Create a JsonPrimitive of int from the given token

    static JsonBool*                        createBool( Token* t );
      // Create a JsonPrimitive of bool from the given token

    static JsonDouble*                      createDouble( Token* t );
      // Create a JsonPrimitive of double from the given token

    static JsonString*                      createString( Token* t );
      // Create a JsonPrimitive of std::string from the given token

    
    //static JsonEntity*                      newString( Token* t );
      // FIXME: Figure out how to make the allocator works for Json Entities


  public:

    // MEMBER FUNCTIONS

    static JsonEntity*      fromString( const std::string& json,
                                        sgdm::IAllocator<JsonEntity*>* a = 0 );
      // Parse a string into a JsonEntity
      // Should throw an invalid json exception with appropriate information
      // about what segment of json is invalid (char, num,...)
};

} // End sgdd namespace
} // End StevensDev namespace

#endif // INCLUDED_JSON_PARSER
