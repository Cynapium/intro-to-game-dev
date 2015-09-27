#ifndef INCLUDED_JSON_ENTITY
# define INCLUDED_JSON_ENTITY

namespace StevensDev
{
namespace sgdd
{

class JsonEntity
{
  private:
    enum EntityType
    {
        PRIMITIVE,
        OBJECT,
        ARRAY
    }

    EntityType          d_type;
      // Type which represents this JsonEntity


  public:

    // CONSTRUCTORS

    JsonEntity( EntityType type );
      // Construct a new JsonEntity of a specific type


    // ACCESSORS

    EntityType          types();
      // Return the type of the entity


    // OPERATORS
    // TODO: cf. sujet


    // MEMBER FUNCTIONS

/*
    int const           asInt();

    std::string const   asString();

    double const        asDouble();

    JsonArray& const    asArray();
*/
    bool const          isInt();

    bool const          isString();

    bool const          isDouble();

    bool const          isArray();

    bool const          isObject();
};

} // End sgdd namespace
} // End StevensDev namespace

#endif // INCLUDED_JSON_ENTITY

