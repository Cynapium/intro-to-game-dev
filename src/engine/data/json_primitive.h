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

    JsonPrimitive( T value );


    // ACCESSORS

    const T                     value() const;
      // Return the value contained by the primitive type.
};

//
// CONSTRUCTORS
//

template<typename T>
inline
JsonPrimitive<T>::JsonPrimitive( T value )
    : JsonEntity( JsonEntity::UNKNOWN ), d_value( value )
{
}

template<>
inline
JsonPrimitive<int>::JsonPrimitive( int value )
    : JsonEntity( JsonEntity::INTEGER ), d_value( value )
{
}

template<>
inline
JsonPrimitive<std::string>::JsonPrimitive( std::string value )
    : JsonEntity( JsonEntity::STRING ), d_value( value )
{
}

template<>
inline
JsonPrimitive<double>::JsonPrimitive( double value )
    : JsonEntity( JsonEntity::DOUBLE ), d_value( value )
{
}

template<>
inline
JsonPrimitive<bool>::JsonPrimitive( bool value )
    : JsonEntity( JsonEntity::BOOLEAN ), d_value( value )
{
}

//
// ACCESSORS
//

template<typename T>
inline
const T JsonPrimitive<T>::value() const
{
    return d_value;
}

//
// FREE OPERATORS
//

template<typename T>
inline
std::ostream& operator<<( std::ostream& str, const JsonPrimitive<T>* prim )
{
    return str << prim->value();
}

template<>
inline
std::ostream& operator<<( std::ostream& str,
                          const JsonPrimitive<std::string>* prim )
{
    return str << "\"" << prim->value() << "\"";
}

// Typedef for primitives types

typedef JsonPrimitive<std::string>  JsonString;
typedef JsonPrimitive<int>          JsonInt;
typedef JsonPrimitive<double>       JsonDouble;
typedef JsonPrimitive<bool>         JsonBool;


} // End sgdd namespace
} // End StevensDev namespace

#endif // INCLUDED_JSON_PRIMITIVE
