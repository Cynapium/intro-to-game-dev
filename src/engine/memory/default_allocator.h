// default_allocator.h

#ifndef INCLUDED_DEFAULT_ALLOCATOR
# define INCLUDED_DEFAULT_ALLOCATOR

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


    // MEMBER FUNCTIONS

    T*          get( int count );
      //

    void        release( T* ptr, int count );
      //
};

template<typename T>
inline DefaultAllocator<T>::DefaultAllocator()
{
}

template<typename T>
inline T* DefaultAllocator<T>::get( int count )
{
    // Error checking
    if (count <= 0)
        return 0;

    // Create the value
    T       *val = new T[count];

    // Return the memory
    return val;
}

template<typename T>
inline void DefaultAllocator<T>::release( T* ptr, int count )
{
    // Error checking
    if (ptr == 0)
        return;

    // Release the memory
    for (int i = 0; i < count; i++)
    {
        delete ptr[i];
    }
    delete[] ptr;
}

} // End sgdm namespace
} // End StevensDev namespace

#endif // INCLUDED_DEFAULT_ALLOCATOR
