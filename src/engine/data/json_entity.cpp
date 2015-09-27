#include "json_entity.h"

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


// MEMBER FUNCTIONS

bool const
JsonEntity::isInt()
{
    return d_type == INTEGER;
}

bool const
JsonEntity::isString()
{
    return d_type == STRING;
}

bool const
JsonEntity::isDouble()
{
    return d_type == DOUBLE;
}

bool const
JsonEntity::isBool()
{
    return d_type == BOOLEAN;
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
