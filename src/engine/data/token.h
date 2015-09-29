// token.h

#ifndef INCLUDED_TOKEN
# define INCLUDED_TOKEN

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
    BOOLEAN,
    NULLPTR
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
                return "}";
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
            case NULLPTR:
                return "NULL";
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


} // End sgdd namespace
} // End StevensDev namespace

#endif // INCLUDED_TOKEN
