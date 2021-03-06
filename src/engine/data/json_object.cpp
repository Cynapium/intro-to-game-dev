// json_object.cpp

#include "json_object.h"

namespace StevensDev
{
namespace sgdd
{

// CONSTRUCTORS

JsonObject::JsonObject( MapJEntity attributes )
    : JsonEntity( JsonEntity::OBJECT ), d_attributes( attributes )
{
}


// ACCESSORS

const MapJEntity&
JsonObject::attributes() const
{
    return d_attributes;
}


// OPERATORS

const JsonEntity&
JsonObject::operator[]( std::string key )
{
    return *( d_attributes[key] );
}


} // End sgdd namespace
} // End StevensDev namespace

