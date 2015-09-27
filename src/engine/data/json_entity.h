#ifndef INCLUDED_JSON_ENTITY
# define INCLUDED_JSON_ENTITY

#include <iostream>
#include <string>
#include "../containers/dynamic_array.h"

namespace StevensDev
{
namespace sgdd
{

class JsonEntity
{
  public:

    enum EntityType
    {
      // Primitive types
        STRING,
        INTEGER,
        BOOLEAN,
        DOUBLE,

      // Object
        OBJECT,

      // Array
        ARRAY,

      // In case of error
        UNKNOWN
    };


  private:

    EntityType          d_type;
      // Type which represents this JsonEntity


  public:

    // CONSTRUCTORS

    JsonEntity( EntityType type );
      // Construct a new JsonEntity of a specific type


    // ACCESSORS

    EntityType          type() const;
      // Return the type of the entity

    std::string         typeStr() const;
      // Return a string representing the type of the entity


    // OPERATORS
    // TODO: cf. sujet


    // MEMBER FUNCTIONS

    int const           asInt() const;

    std::string const   asString() const;

    double const        asDouble() const;

    bool const          asBool() const;

    const sgdc::DynamicArray<JsonEntity*>& asArray() const;


    bool const          isInt() const;
      // Return true if type is int

    bool const          isString() const;
      // Return true if type is std::string

    bool const          isDouble() const;
      // Return true if type is double

    bool const          isBool() const;
      // Return true if type is bool

    bool const          isArray() const;
      // Return true if type is an array

    bool const          isObject() const;
      // Return true if type is an object

};

inline
std::ostream&
operator<<( std::ostream& str, const JsonEntity* entity )
{
    switch ( entity->type() )
    {
/*
        case JsonEntity::OBJECT:
            return str << *( ( JsonObject* ) entity );
            */

        case JsonEntity::ARRAY:
            return str << entity->asArray();

        case JsonEntity::INTEGER:
            return str << entity->asInt();

        case JsonEntity::STRING:
            return str << entity->asString();

        case JsonEntity::DOUBLE:
            return str << entity->asDouble();

        case JsonEntity::BOOLEAN:
            return str << entity->asBool();

        default:
            return str << "{ UNKNOWN ENTITY }";
    }
}


} // End sgdd namespace
} // End StevensDev namespace


#endif // INCLUDED_JSON_ENTITY

