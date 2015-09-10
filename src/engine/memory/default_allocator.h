// default_allocator.h

#ifndef INCLUDED_DEFAULT_ALLOCATOR
# define INCLUDED_DEFAULT_ALLOCATOR

#include "iallocator.h"

namespace sgdm
{

template<typename T>
class DefaultAllocator : public IAllocator<T>
{
  public:
    T*          get( int count );
      //

    void        release( T* ptr, int count );
      //
};

#include "default_allocator.cxx"

} // End sgdm namespace

#endif // INCLUDED_DEFAULT_ALLOCATOR
