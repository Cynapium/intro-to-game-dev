// json_array.cpp

#include "json_array.h"

namespace StevensDev
{
namespace sgdd
{

// CONSTRUCTORS

JsonArray::JsonArray( ArrayJEntity array )
    : JsonEntity( JsonEntity::ARRAY ), d_array( array )
{
}


// ACCESSORS

const ArrayJEntity&
JsonArray::array() const
{
    return d_array;
}


// OPERATORS

const JsonEntity&
JsonArray::operator[]( int index )
{
    return *( d_array[index] );
}


} // End sgdd namespace
} // End StevensDev namespace
