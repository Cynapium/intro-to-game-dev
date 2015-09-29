// token_primitive.h

#ifndef INCLUDED_TOKEN_PRIMITIVE
# define INCLUDED_TOKEN_PRIMITIVE

#include "token.h"

namespace StevensDev
{
namespace sgdd
{

template<typename T>
class TokenPrimitive : public Token
{
  private:

    T                       d_value;
      // Primitive value we want to store inside a Token

  public:

    // CONSTRUCTOR

    TokenPrimitive( TokenType t, T v );
      // Initialize a Token with a primitive type and a value

    // ACCESSOR

    T                       value();
      // Return the primitive value
};


// CONSTRUCTORS

template<typename T>
inline
TokenPrimitive<T>::TokenPrimitive( TokenType type, T value )
    : Token( type ), d_value( value )
{
}


template<typename T>
inline
T TokenPrimitive<T>::value()
{
    return d_value;
}

// Typedef for primitives types

typedef TokenPrimitive<std::string>  TokenString;
typedef TokenPrimitive<int>          TokenInt;
typedef TokenPrimitive<double>       TokenDouble;
typedef TokenPrimitive<bool>         TokenBool;

} // End sgdd namespace
} // End StevensDev namespace

#endif // INCLUDED_TOKEN_PRIMITIVE
