#ifndef INCLUDED_JSON_PRIMITIVE
# define INCLUDED_JSON_PRIMITIVE

#include "json_entity.h"
#include <exception>
#include <string>

namespace StevensDev
{
namespace sgdd
{

template<typename T>
class JsonPrimitive : public JsonEntity
{
  private:

    T                           d_value;


  public:

    // CONSTRUCTORS

    JsonPrimitive( T value )
        : JsonEntity( JsonEntity::PRIMITIVE ), d_value( value )
    {
    }


    // ACCESSORS

    T                           value()
    {
        return d_value;
    }


    // MEMBER FUNCTIONS

    int const           asInt();

    std::string const   asString();
};

template<typename T>
inline
int const JsonPrimitive<T>::asInt()
{
    throw std::exception(); //TODO
}

template<>
inline
int const JsonPrimitive<int>::asInt()
{
    return d_value;
}

template<typename T>
inline
std::string const JsonPrimitive<T>::asString()
{
    throw std::exception(); // TODO
}

template<>
inline
std::string const JsonPrimitive<std::string>::asString()
{
    return d_value;
}

// Typedef for primitives types

typedef JsonPrimitive<std::string>  JsonString;
typedef JsonPrimitive<int>          JsonInt;
typedef JsonPrimitive<double>       JsonDouble;
typedef JsonPrimitive<bool>         JsonBool;


} // End sgdd namespace
} // End StevensDev namespace

#endif // INCLUDED_JSON_PRIMITIVE
