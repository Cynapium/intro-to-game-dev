#ifndef INCLUDE_DYNAMIC_ARRAY
# define INCLUDE_DYNAMIC_ARRAY

#include "../memory/iallocator.h"

namespace StevensDev
{
namespace sgdc
{

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


    // MEMBER FUNCTIONS

    void            shiftRight( unsigned int index );
      // Shift the array to the right, starting at index value

    void            shiftLeft( unsigned int index );
      // Shift the array to the left, starting at index value

    void            reallocate();
      // Double the size of the array


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

    T               operator[]( int index ) const;
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

    T               insertAt( unsigned int index, const T& element );
      // Can grow, shifts
};

template<typename T>
inline DynamicArray<T>::DynamicArray( sgdm::IAllocator<T>* alloc )
    : d_allocator( alloc ), d_array( 0 ), d_length( 0 ), d_size( 0 )
{
    d_array = alloc->get(1);
    d_size = 1;
}

template<typename T>
inline unsigned int const DynamicArray<T>::getLength()
{
    return d_length;
}

template<typename T>
inline const T DynamicArray<T>::at( unsigned int index )
{
    return *(d_array + index);
}

template<typename T>
inline T DynamicArray<T>::operator[]( int index )
{
    d_array[index] = 0; // TODO, what are we supposed to insert?

    return d_array[index];
}

template<typename T>
T DynamicArray<T>::operator[]( int index ) const
{
    return d_array[index];
}

template<typename T>
inline void DynamicArray<T>::push( const T& element)
{
    insertAt( d_length, element );
}

template<typename T>
inline void DynamicArray<T>::pushFront( T element )
{
    insertAt( 0, element );
}

template<typename T>
inline T DynamicArray<T>::pop()
{
    // Error checking
    if ( d_length <= 0 )
        return 0;

    // Decrease size of the array and return the last element
    d_length--;
    return d_array[d_length];
}

template<typename T>
inline T DynamicArray<T>::popFront()
{
    // Error checking
    if ( d_length <= 0 )
        return 0;

    // Keep the element to return
    T ret = d_array[0];

    // Shift and decrease size
    shiftLeft( 0 );
    d_length--;

    // Return
    return ret;
}

template<typename T>
inline T DynamicArray<T>::removeAt( unsigned int index )
{
    // Error checking
    if ( index < 0 || index > d_length )
        return 0; // TODO: Throw exception

    // Decrease size and shift array
    shiftLeft( index );
    d_length--;
}

template<typename T>
inline T DynamicArray<T>::insertAt( unsigned int index, const T& element )
{
    // Error checking
    if ( index < 0 || index > d_length )
        return 0; // TODO: Throw exception

    // Allocate new memory if needed
    if ( d_length >= d_size)
        reallocate();

    // Shift array and increase size
    shiftRight( index );
    d_length++;

    // Insert
    d_array[index] = element;

    // Return
    return element;
}

template<typename T>
inline void DynamicArray<T>::shiftRight( unsigned int index )
{
    // Error checking
    if ( index < 0 || index > d_length )
        return; // TODO: Throw exception

    // Check if allocated size is enough
    if (d_length + 1 >= d_size)
        reallocate();

    // Shift to the right
    for (int i = d_length; i > index; i--)
    {
        d_array[i] = d_array[i - 1];
    }
}

template<typename T>
inline void DynamicArray<T>::shiftLeft( unsigned int index )
{
    // Error checking
    if ( index < 0 || index > d_length )
        return; // TODO: Throw exception

    // Shift to the left
    for (int i = index; i < d_length; i++)
    {
        d_array[i] = d_array[i + 1];
    }
}

template<typename T>
inline void DynamicArray<T>::reallocate()
{
    unsigned int    new_size = d_size * 2;
    T*              new_array = d_allocator->get(new_size);

    // Move the values from d_array to the new memory space
    for (int i = 0; i < d_length; i++)
    {
        new_array[i] = d_array[i];
    }

    // Release the old memory space
    d_allocator->release(d_array, d_size);

    // Update values of the array
    d_size = new_size;
    d_array = new_array;
}

} // End sgdc namespace
} // End StevensDev namespace

#endif // INCLUDE_DYNAMIC_ARRAY
