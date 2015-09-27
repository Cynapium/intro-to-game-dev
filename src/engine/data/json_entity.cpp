#include "json_entity.hh"

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

EntityType
JsonEntity::type()
{
    return d_type;
}


// MEMBER FUNCTIONS

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
    if ( d_type == ARRAY )
    {
        return true;
    }

    return false;
}

bool const
JsonEntity::isObject()
{
    if ( d_type == OBJECT )
    {
        return true;
    }

    return false;
}

} // End sgdd namespace
} // End StevensDev namespace
