// counting_allocator.h

#ifndef INCLUDED_COUNTING_ALLOCATOR
# define INCLUDED_COUNTING_ALLOCATOR

#include "default_allocator.h"

namespace sgdm
{

template<typename T>
class CountingAllocator<T> : public DefaultAllocator
{
  private:

    int         d_allocation_count;
    int         d_release_count;
    static int  d_total_allocation_count;
    static int  d_total_release_count;


  public:

    // CONSTRUCTOR
    CountingAllocator();

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

    static int  getOutstandingCount();
      // Allocations - releases across instances

};

// Static variables instantiation
int CountingAllocator::d_total_allocation_count = 0;
int CountingAllocator::d_total_release_count = 0;

#include "counting_allocator.cxx"

} // End sgdm namespace

#endif // INCLUDED_COUNTING_ALLOCATOR

