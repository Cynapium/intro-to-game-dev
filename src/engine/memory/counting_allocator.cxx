// counting_allocator.cxx

#include "counting_allocator.h"

namespace sgdm
{

template<typename T>
CountingAllocator<T>::CountingAllocator()
    : d_allocation_count( 0 ), d_release_count( 0 )
{
}

template<typename T>
int const CountingAllocator<T>::getAllocationCount()
{
    return d_allocation_count;
}
 
template<typename T>
int const CountingAllocator<T>::getReleaseCount()
{
    return d_release_count;
}
 
template<typename T>
int const CountingAllocator<T>::getOutstandingCount()
{
    return d_allocation_count - d_release_count;
}
 
template<typename T>
static int CountingAllocator<T>::getTotalAllocationCount()
{
    return d_total_allocation_count;
}

template<typename T>
static int CountingAllocator<T>::getTotalReleaseCount()
{
    return d_total_release_count;
}
 
template<typename T>
static int CountingAllocator<T>::getOutstandingCount()
{
    return d_total_allocation_count - d_total_release_count;
}
 
} // End sgdm namespace
