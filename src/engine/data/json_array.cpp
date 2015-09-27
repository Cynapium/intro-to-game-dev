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

ArrayJEntity
JsonArray::array()
{
    return d_array;
}

const ArrayJEntity&
JsonArray::asArray() const
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
