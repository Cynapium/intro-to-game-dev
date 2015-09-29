// token.cpp

#include "token.h"

namespace StevensDev
{
namespace sgdd
{

// CONSTRUCTOR

Token::Token( TokenType t )
    : d_type( t )
{
}

// ACCESSORS

TokenType
Token::type()
{
    return d_type;
}

// MUTATORS

void
Token::setType( TokenType type )
{
    d_type = type;
}

// MEMBER FUNCTIONS

std::string
Token::typeStr()
{
    switch ( type() )
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

} // End sgdd namespace
} // End StevensDev namespace

