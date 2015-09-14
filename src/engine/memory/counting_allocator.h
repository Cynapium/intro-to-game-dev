// counting_allocator.h

#ifndef INCLUDED_COUNTING_ALLOCATOR
# define INCLUDED_COUNTING_ALLOCATOR

#include "default_allocator.h"

namespace StevensDev
{
namespace sgdm
{

template<typename T>
class CountingAllocator : public DefaultAllocator<T>
{
  private:

    int         d_allocation_count;
    int         d_release_count;
    static int  d_total_allocation_count;
    static int  d_total_release_count;


  public:

    // CONSTRUCTOR

    CountingAllocator();
      // Instantiate a CountingAllocator

    // ACCESSORS

    int const   getAllocationCount();
      // Number of allocations that occured

    int const   getReleaseCount();
      // Number of releases that occured

    int const   getOutstandingCount();
      // Allocations - releases

    static int  getTotalAllocationCount();
      // Number of allocations across instances

    static int  getTotalReleaseCount();
      // Number of releases across instances

    static int  getTotalOutstandingCount();
      // Allocations - releases across instances

};

// Static variables instantiation
template<typename T>
int CountingAllocator<T>::d_total_allocation_count = 0;

template<typename T>
int CountingAllocator<T>::d_total_release_count = 0;

// CONSTRUCTOR
template<typename T>
CountingAllocator<T>::CountingAllocator()
    : d_allocation_count( 0 ), d_release_count( 0 )
{
}

// ACCESSORS
template<typename T>
inline int const CountingAllocator<T>::getAllocationCount()
{
    return d_allocation_count;
}

template<typename T>
inline int const CountingAllocator<T>::getReleaseCount()
{
    return d_release_count;
}

template<typename T>
inline int const CountingAllocator<T>::getOutstandingCount()
{
    return d_allocation_count - d_release_count;
}

template<typename T>
inline int CountingAllocator<T>::getTotalAllocationCount()
{
    return d_total_allocation_count;
}

template<typename T>
inline int CountingAllocator<T>::getTotalReleaseCount()
{
    return d_total_release_count;
}

template<typename T>
inline int CountingAllocator<T>::getTotalOutstandingCount()
{
    return d_total_allocation_count - d_total_release_count;
}


} // End sgdm namespace
} // End StevensDev namespace

#endif // INCLUDED_COUNTING_ALLOCATOR

