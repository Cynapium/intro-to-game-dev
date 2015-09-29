// json_entity.cpp

#include "json_entity.h"
#include "json_primitive.h"
#include "json_array.h"
#include "json_object.h"
#include <exception>

namespace StevensDev
{
namespace sgdd
{

// CONSTRUCTORS

JsonEntity::JsonEntity(EntityType type)
    : d_type( type )
{
}

// ACCESSORS

JsonEntity::EntityType
JsonEntity::type() const
{
    return d_type;
}

std::string
JsonEntity::typeStr() const
{
    switch ( d_type )
    {
        case STRING:
            return "STRING";

        case INTEGER:
            return "INTEGER";

        case BOOLEAN:
            return "BOOLEAN";

        case DOUBLE:
            return "DOUBLE";

        case OBJECT:
            return "OBJECT";

        case ARRAY:
            return "ARRAY";

        default:
            return "error";
    }
}


// OPERATORS

const JsonEntity& 
JsonEntity::operator[]( std::string& key )
{
    if ( isObject() )
        return *( ( ( JsonObject* ) this )->attributes()[key] );

    throw std::exception();
}

const JsonEntity&
JsonEntity::operator[]( int i )
{
    if ( isArray() )
        return *( ( ( JsonArray* ) this )->array()[i] );

    throw std::exception();
}


// MEMBER FUNCTIONS

int const
JsonEntity::asInt() const
{
    if ( isInt() )
        return ( ( JsonInt* ) this )->value();

    throw std::exception();
}

std::string const
JsonEntity::asString() const
{
    if ( isString() )
        return ( ( JsonString* ) this )->value();

    throw std::exception();
}

double const
JsonEntity::asDouble() const
{
    if ( isDouble() )
        return ( ( JsonDouble* ) this )->value();

    throw std::exception();
}

bool const
JsonEntity::asBool() const
{
    if ( isBool() )
        return ( ( JsonBool* ) this )->value();

    throw std::exception();
}

const sgdc::DynamicArray<JsonEntity*>&
JsonEntity::asArray() const
{
    if ( isArray() )
        return ( ( JsonArray* ) this )->array();

    throw std::exception();
}

const sgdc::Map<JsonEntity*>&
JsonEntity::asObject() const
{
    if ( isObject() )
        return ( ( JsonObject* ) this )->attributes();

    throw std::exception();
}

bool const
JsonEntity::isInt() const
{
    return d_type == INTEGER;
}

bool const
JsonEntity::isString() const
{
    return d_type == STRING;
}

bool const
JsonEntity::isDouble() const
{
    return d_type == DOUBLE;
}

bool const
JsonEntity::isBool() const
{
    return d_type == BOOLEAN;
}

bool const
JsonEntity::isArray() const
{
    return d_type == ARRAY;
}

bool const
JsonEntity::isObject() const
{
    return d_type == OBJECT;
}

} // End sgdd namespace
} // End StevensDev namespace
