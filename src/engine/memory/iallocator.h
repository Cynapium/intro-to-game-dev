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
};



} // End sgdm namespace
} // End StevensDev namespace

#endif // INCLUDED_IALLOCATOR
