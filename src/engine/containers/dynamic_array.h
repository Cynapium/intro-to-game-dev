// dynamic_array.h

#ifndef INCLUDED_DYNAMIC_ARRAY
# define INCLUDED_DYNAMIC_ARRAY

#include <stdexcept>
#include "memory/default_allocator.h"
#include "memory/iallocator.h"

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
      // Array where data are stored

    unsigned int    d_length;
      // Number of elements contained

    unsigned int    d_size;
      // Size of the array allocation


    // MEMBER FUNCTIONS
    // These functions are private because we don't want them to be used in a
    // bad way, outside the class.

    void            shiftRight( unsigned int index );
      // Shift the array to the right, starting at index value

    void            shiftLeft( unsigned int index );
      // Shift the array to the left, starting at index value

    void            reallocate();
      // This function increase the size of the array. When the array is full,
      // it allocate a new array twice as large (size * 2). That strategy
      // allows us to reduce the reallocation cost logarithmically.
      // Returns true if reallocation was successful, false otherwise.


  public:

    // CONSTRUCTORS

    DynamicArray();
      // Default constructor

    DynamicArray( IAllocator<T>* alloc );
      // Pointer to an allocator for use with memory

    DynamicArray( const DynamicArray<T>& copy );
      // Copy constructor


    // DESTRUCTOR

    virtual             ~DynamicArray();
      // Delete everything


    // OPERATORS

    DynamicArray&       operator=( const DynamicArray& array );
      // Copy assignment operator

    T&                  operator[]( int index );
      // Sets an element, undefined behavior if out of bounds

    T                   operator[]( int index ) const;
      // Retrieves an element, undefined behaviour if out of bounds


    // ACCESSORS

    unsigned int const  length() const;
      // Number of elements contained

    const T             at( unsigned int index );
      // Retrieves an element at a location, throws if out of bounds


    // MEMBER FUNCTIONS

    void                push( const T& element );
      // Adds element to end of collection, grow

    void                pushFront( T element );
      // Pushes to the front of the collection, grow, shift

    T                   pop();
      // Removes and retrieve the last element, shifts

    T                   popFront();
      // Removes and retrieve the first element, shifts

    T                   removeAt( unsigned int index );
      // Removes, throws if invalid, shifts

    T                   insertAt( unsigned int index, const T& element );
      // Can grow, shifts
};


// PRIVATE MEMBER FUNCTIONS
// Declared first because private

template<typename T>
inline
void DynamicArray<T>::shiftRight( unsigned int index )
{
    // Error checking
    if ( index < 0 || index > d_length )
        throw std::out_of_range( "DynamicArray::shiftRight: out of range" );

    // Check if allocated size is enough
    if (d_length + 1 > d_size)
        reallocate();

    // Shift to the right
    for ( int i = d_length; i > index; i-- )
    {
        d_array[i] = d_array[i - 1];
    }
}

template<typename T>
inline
void DynamicArray<T>::shiftLeft( unsigned int index )
{
    // Error checking
    if ( index < 0 || index > d_length )
        throw std::out_of_range( "DynamicArray::shiftLeft: out of range" );

    // Shift to the left
    for ( int i = index; i < d_length; i++ )
    {
        d_array[i] = d_array[i + 1];
    }
}

template<typename T>
inline
void DynamicArray<T>::reallocate()
{
    // Initialization
    unsigned int    new_size = d_size * 2;

    // Allocate and check if new memory is valid
    T*              new_array = d_allocator->get( new_size );

    if ( new_array == nullptr )
    {
        throw std::bad_alloc();
    }

    // Move the values from d_array to the new memory space
    for ( int i = 0; i < d_length; i++ )
    {
        new_array[i] = d_array[i];
    }

    // Release the old memory space
    d_allocator->release( d_array, d_size );

    // Update values of the array
    d_size = new_size;
    d_array = new_array;
}


// CONSTRUCTORS

template<typename T>
inline
DynamicArray<T>::DynamicArray()
    : d_allocator( new DefaultAllocator<T> ), d_array( 0 ),
    d_length( 0 ), d_size( 0 )
{
    // Size is two because we want to create a dynamic array, and we don't know
    // the final number of element we want. 1 is not an array thus will have to
    // be reallocate in every case, and we don't know if we need more than 2.
    int     size = 2;

    d_array = d_allocator->get( size );
    d_size = size;
}

template<typename T>
inline
DynamicArray<T>::DynamicArray( sgdm::IAllocator<T>* alloc )
    : d_allocator( alloc ), d_array( 0 ),
    d_length( 0 ), d_size( 0 )
{
    int     size = 2;

    d_array = alloc->get( size );
    d_size = size;
}

template<typename T>
inline
DynamicArray<T>::DynamicArray( const DynamicArray<T>& copy )
    : d_allocator( copy.d_allocator ), d_array( 0 ),
    d_length( copy.d_length ), d_size( copy.d_size )
{
    d_array = d_allocator->get( d_size );

    for ( int i = 0; i < d_length; i++ )
        d_array[i] = copy.d_array[i];
}


// DESTRUCTOR

template<typename T>
inline
DynamicArray<T>::~DynamicArray()
{
    d_allocator->release( d_array, d_size );
}


// OPERATORS

template<typename T>
inline
DynamicArray<T>& DynamicArray<T>::operator=( const DynamicArray<T>& array )
{
    d_allocator = array.d_allocator;
    d_length = array.d_length;
    d_size = array.d_size;

    for ( int i = 0; i < d_length; i++ )
        d_array[i] = array.d_array[i];

    return *this;
}

template<typename T>
inline
T& DynamicArray<T>::operator[]( int index )
{
    return d_array[index];
}

template<typename T>
inline
T DynamicArray<T>::operator[]( int index ) const
{
    return d_array[index];
}


// ACCESSORS

template<typename T>
inline
unsigned int const DynamicArray<T>::length() const
{
    return d_length;
}

template<typename T>
inline
const T DynamicArray<T>::at( unsigned int index )
{
    // Error checking
    if ( index < 0 || index >= d_length )
        throw std::out_of_range( "DynamicArray::at: out of range" );

    return d_array[index];
}


// MEMBER FUNCTIONS

template<typename T>
inline
void DynamicArray<T>::push( const T& element )
{
    insertAt( d_length, element );
}

template<typename T>
inline
void DynamicArray<T>::pushFront( T element )
{
    insertAt( 0, element );
}

template<typename T>
inline
T DynamicArray<T>::pop()
{
    // Error checking
    if ( d_length <= 0 )
        return 0;

    // Decrease size of the array and return the last element
    d_length--;
    return d_array[d_length];
}

template<typename T>
inline
T DynamicArray<T>::popFront()
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
inline
T DynamicArray<T>::removeAt( unsigned int index )
{
    // Error checking
    if ( index < 0 || index > d_length )
        throw std::out_of_range( "DynamicArray::shiftLeft: out of range" );

    // Retrieve the element
    T       element = d_array[index];

    // Decrease size and shift array
    shiftLeft( index );
    d_length--;

    return element;
}

template<typename T>
inline
T DynamicArray<T>::insertAt( unsigned int index, const T& element )
{
    // Error checking
    if ( index < 0 || index > d_length )
        throw std::out_of_range( "DynamicArray::shiftLeft: out of range" );

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


// FREE OPERATORS

template<class T>
inline std::ostream&
operator<<( std::ostream& stream, const DynamicArray<T> array )
{
    stream << "[ ";

    for ( int i = 0; i < array.length(); i++ )
    {
        if ( i > 0 )
        {
            stream << ", ";
        }
        stream << array[i];
    }

    return stream << " ]";
}


} // End sgdc namespace
} // End StevensDev namespace

#endif // INCLUDED_DYNAMIC_ARRAY
