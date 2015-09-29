// token.h

#ifndef INCLUDED_TOKEN
# define INCLUDED_TOKEN

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
    BOOLEAN,
    NULLPTR
};

class Token
{
  private:
    TokenType               d_type;
      // Type of the token

  public:

    // CONSTRUCTOR
    Token( TokenType t );
      // Create a new token of type t

    // ACCESSORS
    TokenType               type();
      // Return the type of the Token

    // MUTATORS
    void                    setType( TokenType type );
      // Set the token's type

    // MEMBER FUNCTIONS
    std::string             typeStr();
      // Return a string representing the type of the token
};


} // End sgdd namespace
} // End StevensDev namespace

#endif // INCLUDED_TOKEN
