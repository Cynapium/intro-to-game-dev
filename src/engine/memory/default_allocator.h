// default_allocator.h

#ifndef INCLUDED_DEFAULT_ALLOCATOR
# define INCLUDED_DEFAULT_ALLOCATOR

#include <iostream>
#include "iallocator.h"

namespace StevensDev
{
namespace sgdm
{

template<typename T>
class DefaultAllocator : public IAllocator<T>
{
  public:

    // CONSTRUCTOR

    DefaultAllocator();
      // Instantiate a default allocator

    DefaultAllocator( const DefaultAllocator<T>& allocator );
      // Copy Constructor


    // DESTRUCTOR

    virtual             ~DefaultAllocator();


    // OPERATORS
    DefaultAllocator&   operator=( const DefaultAllocator& allocator );
      // Copy assignment operator


    // MEMBER FUNCTIONS

    T*                  get( int count );
      // Allocate memory

    void                release( T* ptr, int count );
      // Release allocated memory
};

// CONSTRUCTORS

template<typename T>
inline
DefaultAllocator<T>::DefaultAllocator()
{
}

template<typename T>
inline
DefaultAllocator<T>::DefaultAllocator( const DefaultAllocator<T>& copy )
{
}

// DESTRUCTOR

template<typename T>
inline
DefaultAllocator<T>::~DefaultAllocator()
{
}

// OPERATORS

template<typename T>
inline
DefaultAllocator<T>&
DefaultAllocator<T>::operator=( const DefaultAllocator<T>& allocator )
{
    return *this;
}


// MEMBER FUNCTIONS

template<typename T>
inline
T* DefaultAllocator<T>::get( int count )
{
    // Error checking
    if ( count <= 0 )
        return 0;

    // Create the value
    T       *ptr = new T[count];

    // Return the memory
    return ptr;
}

template<typename T>
inline
void DefaultAllocator<T>::release( T* ptr, int count )
{
    // Error checking
    if ( ptr == 0 )
        return;

    // Release the memory
    for ( int i = 0; i < count; i++ )
    {
        //delete ptr[i];
    }
    delete[] ptr;

    ptr = 0;
}


// FREE OPERATORS

template<class T>
inline
std::ostream&
operator<<( std::ostream& stream, const DefaultAllocator<T> allocator )
{
    return stream << "{ DefaultAllocator }";
}


} // End sgdm namespace
} // End StevensDev namespace

#endif // INCLUDED_DEFAULT_ALLOCATOR
