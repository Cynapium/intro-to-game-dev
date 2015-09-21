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

    //virtual void    construct( T* ptr, Args&&... args ) = 0;
      //
    
    virtual void    construct( T* ptr, const T& copy ) = 0;
      //

    virtual void    destruct( T* ptr ) = 0;
      //
};



} // End sgdm namespace
} // End StevensDev namespace

#endif // INCLUDED_IALLOCATOR
