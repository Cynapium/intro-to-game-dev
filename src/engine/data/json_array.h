// json_array.h

#ifndef INCLUDED_JSON_ARRAY
# define INCLUDED_JSON_ARRAY

#include "containers/dynamic_array.h"
#include "data/json_entity.h"

namespace StevensDev
{
namespace sgdd
{

typedef sgdc::DynamicArray<JsonEntity*> ArrayJEntity;

class JsonArray : public JsonEntity
{
  private:

    ArrayJEntity                d_array;
      // Array of pointer to JsonEntity


  public:

    // CONSTRUCTORS

    JsonArray( ArrayJEntity array );


    // ACCESSORS

    const ArrayJEntity&               array() const;
      // Return the array of JsonEntity


    // OPERATORS

    const JsonEntity&           operator[]( int index );
      // Retrieve the element stored at the index i

};

// FREE OPERATOR

inline std::ostream&
operator<<( std::ostream& str, const JsonArray jarray )
{
        return str << jarray.array();
}

} // End sgdd namespace
} // End StevensDev namespace

#endif // INCLUDED_JSON_ARRAY
