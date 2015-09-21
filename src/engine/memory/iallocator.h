// iallocator.h

#ifndef INCLUDED_IALLOCATOR
# define INCLUDED_IALLOCATOR

namespace StevensDev
{
namespace sgdm
{

template<typename T>
class IAllocator
{
  public:
    virtual T*      get( int count ) = 0;
      // Allocate memory

    virtual void    release( T* ptr, int count ) = 0;
      // Release allocated memory

    virtual void    construct( T* ptr, T&& copy ) = 0;
      // Construct a T object in-place by move
    
    virtual void    construct( T* ptr, const T& copy ) = 0;
      // Construct a T object in-place by copy

    virtual void    destruct( T* ptr ) = 0;
      // Call the destructor on an object
};



} // End sgdm namespace
} // End StevensDev namespace

#endif // INCLUDED_IALLOCATOR
