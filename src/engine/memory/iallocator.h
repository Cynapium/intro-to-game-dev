// iallocator.h

#ifndef INCLUDED_IALLOCATOR
# define INCLUDED_IALLOCATOR

namespace sgdm
{

template<class T>
class IAllocator
{
  public:
    T*          get( int count ) = 0;
      //

    void        release( T* ptr, int count ) = 0;
      //
};



} // End sgdm namespace

#endif // INCLUDED_IALLOCATOR
