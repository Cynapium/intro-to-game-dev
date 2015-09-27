#ifndef INCLUDED_JSON_PARSER
# define INCLUDED_JSON_PARSER

#include "json_entity.h"
#include "json_primitive.h"
#include "../memory/iallocator.h"
#include <string>

namespace StevensDev
{
namespace sgdd
{

enum TokenType
{
    OPEN_BRACE,
    CLOSE_BRACE,
    OPEN_BRACKET,
    CLOSE_BRACKET,
    COLON,
    COMMA,
    SPACE,
    STRING,
    INTEGER,
    DOUBLE,
    BOOLEAN
};

class Token
{
  public:
    TokenType               type;
    Token( TokenType t ) : type( t ) {}
    std::string             typeStr()
    {
        switch ( type )
        {
            case OPEN_BRACE:
                return "{";
            case CLOSE_BRACE:
                return "";
            case OPEN_BRACKET:
                return "[";
            case CLOSE_BRACKET:
                return "]";
            case COLON:
                return ":";
            case COMMA:
                return ",";
            case SPACE:
                return "SPACE";
            case STRING:
                return "STRING";
            case INTEGER:
                return "INTEGER";
            case DOUBLE:
                return "DOUBLE";
            case BOOLEAN:
                return "BOOLEAN";
        }
    }
};

template<typename T>
class TokenPrimitive : public Token
{
  public:
    T                       value;
    TokenPrimitive( TokenType t, T v )
        : Token( t ), value( v )
        {}
};



// Typedef for primitives types

typedef TokenPrimitive<std::string>  TokenString;
typedef TokenPrimitive<int>          TokenInt;
typedef TokenPrimitive<double>       TokenDouble;
typedef TokenPrimitive<bool>         TokenBool;

class JsonParser
{
  private:

    static std::string             d_json;
    static int                     d_index;

    // MEMBER FUNCTIONS

    static Token*           token();
    static JsonEntity*      parseArray();
    //static JsonEntity*      parseObject();
    static JsonEntity*      parseString();

    static JsonString*     asString( Token* t );
    static JsonInt*        asInt( Token* t );
    static JsonDouble*     asDouble( Token* t );
    static JsonBool*       asBool( Token* t );

  public:

    // MEMBER FUNCTIONS

    static JsonEntity*      fromString( const std::string& json);
      // Parse a string into a JsonEntity
      // Should throw an invalid json exception with appropriate information
      // about what segment of json is invalid (char, num,...)
};

} // End sgdd namespace
} // End StevensDev namespace

#endif // INCLUDED_JSON_PARSER
