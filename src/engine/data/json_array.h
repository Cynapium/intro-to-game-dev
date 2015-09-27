#ifndef INCLUDED_JSON_ARRAY
# define INCLUDED_JSON_ARRAY

#include "../containers/dynamic_array.h"
#include "json_entity.h"

namespace StevensDev
{
namespace sgdd
{

typedef sgdc::DynamicArray<JsonEntity*> ArrayJEntity;

class JsonArray : public JsonEntity
{
  private:

    ArrayJEntity                d_array;


  public:

    // CONSTRUCTORS

    JsonArray( ArrayJEntity array );


    // ACCESSORS

    const ArrayJEntity&               array() const;


    // OPERATORS

    const JsonEntity&           operator[]( int index );

};

inline std::ostream&
operator<<( std::ostream& str, const JsonArray jarray )
{
        return str << jarray.array();
}

} // End sgdd namespace
} // End StevensDev namespace

#endif // INCLUDED_JSON_ARRAY
