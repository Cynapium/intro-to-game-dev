#include "json_entity.h"
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
JsonEntity::type()
{
    return d_type;
}

std::string
JsonEntity::typeStr() const
{
    switch ( d_type )
    {
        case PRIMITIVE:
            return "PRIMITIVE";

        case OBJECT:
            return "OBJECT";

        case ARRAY:
            return "ARRAY";

        default:
            return "error";
    }
}


// MEMBER FUNCTIONS

int const
JsonEntity::asInt()
{
    throw std::exception();
}

std::string const
JsonEntity::asString()
{
    throw std::exception();
}

bool const
JsonEntity::isInt()
{
    if ( d_type == PRIMITIVE )
    {
        // TODO Check if int
        return true;
    }

    return false;
}

bool const
JsonEntity::isString()
{
    if ( d_type == PRIMITIVE )
    {
        // TODO Check if str
        return true;
    }

    return false;
}

bool const
JsonEntity::isDouble()
{
    if ( d_type == PRIMITIVE )
    {
        // TODO Check if double
        return true;
    }

    return false;
}

bool const
JsonEntity::isArray()
{
    return d_type == ARRAY;
}

bool const
JsonEntity::isObject()
{
    return d_type == OBJECT;
}

} // End sgdd namespace
} // End StevensDev namespace
