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
      //

    virtual void    release( T* ptr, int count ) = 0;
      //
};



} // End sgdm namespace
} // End StevensDev namespace

#endif // INCLUDED_IALLOCATOR
