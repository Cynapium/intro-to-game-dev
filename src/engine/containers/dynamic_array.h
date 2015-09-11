#ifndef INCLUDE_DYNAMIC_ARRAY
# define INCLUDE_DYNAMIC_ARRAY

#include "../memory/iallocator.h"

namespace StevensDev
{
namespace sgdc
{

// FIXME There should be a better way
#define ALLOC_SIZE  64

using namespace sgdm;

template<typename T>
class DynamicArray
{
private:

    IAllocator<T>  *d_allocator;
      // Allocator used to manage memory in the dynamic array

    T              *d_array;
      // Array where data is stored

    unsigned int    d_length;
      // Number of elements contained

    unsigned int    d_size;
      // Size of the array allocation


    void            shift( unsigned int index, bool shiftLeft );

public:

    // CONSTRUCTOR
    
    DynamicArray( IAllocator<T>* alloc );
      // Pointer to an allocator for use with memory


    // ACCESSORS

    unsigned int const getLength();
      // Number of elements contained

    const T         at( unsigned int index );
      // Retrieves an element at a location, throws if out of bounds


    // OPERATORS

    T               operator[]( int index );
      // Sets an element, undefined behavior if out of bounds

    //const T         operator[]( int index );
      // Retrieves an element, undefined behaviour if out of bounds


    // MEMBER FUNCTIONS

    void            push( const T& element);
      // Adds element to end of collection, grow

    void            pushFront( T element );
      // Pushes to the front of the collection, grow, shift

    T               pop();
      // Removes and retrieve the last element, shifts

    T               popFront();
      // Removes and retrieve the first element, shifts

    T               removeAt( unsigned int index );
      // Removes, throws if invalid, shifts

    T               insertAt( unsigned int index );
      // Can grow, shifts
};

#include "dynamic_array.cxx"

} // End sgdc namespace
} // End StevensDev namespace

#endif // INCLUDE_DYNAMIC_ARRAY
