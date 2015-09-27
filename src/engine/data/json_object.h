#ifndef INCLUDED_JSON_OBJECT
# define INCLUDED_JSON_OBJECT

#include <string>
#include "../containers/map.h"
#include "json_entity.h"

namespace StevensDev
{
namespace sgdd
{

typedef sgdc::Map<JsonEntity*> MapJEntity;

class JsonObject : JsonEntity
{
  private:

    MapJEntity                  d_attributes;


  public:

    // CONSTRUCTORS

    JsonObject( MapJEntity attributes );


    // ACCESSORS

    MapJEntity                  attributes();


    // OPERATORS

    const JsonEntity&           operator[]( std::string key );
};

} // End sgdd namespace
} // End StevensDev namespace

#endif // INCLUDED_JSON_OBJECT

