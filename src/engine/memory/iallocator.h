// iallocator.h

#ifndef INCLUDED_IALLOCATOR
# define INCLUDED_IALLOCATOR

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

#endif // INCLUDED_IALLOCATOR
