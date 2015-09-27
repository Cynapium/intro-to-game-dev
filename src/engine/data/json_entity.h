#ifndef INCLUDED_JSON_ENTITY
# define INCLUDED_JSON_ENTITY

#include <iostream>
#include <string>

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

    EntityType          type();
      // Return the type of the entity

    std::string         typeStr() const;
      // Return a string representing the type of the entity


    // OPERATORS
    // TODO: cf. sujet


    // MEMBER FUNCTIONS

    virtual int const           asInt();

    virtual std::string const   asString();
/*
    double const        asDouble();

    JsonArray& const    asArray();
*/
    bool const          isInt();
      // Return true if type is int

    bool const          isString();
      // Return true if type is std::string

    bool const          isDouble();
      // Return true if type is double

    bool const          isBool();
      // Return true if type is bool

    bool const          isArray();
      // Return true if type is an array

    bool const          isObject();
      // Return true if type is an object
};

inline std::ostream&
operator<<( std::ostream& str, const JsonEntity* entity )
{
    str << "{ "<< "type: " << entity->typeStr() << "}";

    return str;
}

} // End sgdd namespace
} // End StevensDev namespace

#endif // INCLUDED_JSON_ENTITY

