//
// File: counting_allocator.h
// Author: Barbara Crepeau
//
// Declare CountingAllocator templated class and its functions
//

#ifndef INCLUDED_COUNTING_ALLOCATOR
# define INCLUDED_COUNTING_ALLOCATOR

#include "default_allocator.h"
#include <cassert>

namespace StevensDev
{
namespace sgdm
{

template<typename T>
class CountingAllocator : public DefaultAllocator<T>
{
  private:

    int             d_allocation_count;
      // Number of allocations that occured

    int             d_release_count;
      // Number of releases that occured

    static int      d_total_allocation_count;
      // Number of allocations across instances

    static int      d_total_release_count;
      // Number of releases across instances


  public:

    // CONSTRUCTORS

    CountingAllocator();
      // Instantiate a CountingAllocator

    CountingAllocator( const CountingAllocator<T>& allocator );
      // Copy constructor


    // DESTRUCTOR

    virtual ~CountingAllocator();
      // Destroy the allocator


    // OPERATORS

    CountingAllocator&  operator=( const CountingAllocator& copy );
      // Copy assignment operator


    // ACCESSORS

    int const getAllocationCount();
      // Number of allocations that occured

    int const getReleaseCount();
      // Number of releases that occured

    int const getOutstandingCount();
      // Allocations - releases

    static int getTotalAllocationCount();
      // Number of allocations across instances

    static int getTotalReleaseCount();
      // Number of releases across instances

    static int getTotalOutstandingCount();
      // Allocations - releases across instances


    // MEMBER FUNCTIONS

    virtual T* get( int count );
      // Allocate memory

    virtual void release( T* ptr, int count );
      // Release allocated memory

    virtual void construct( T* ptr, T&& copy );
      // Construct a T object in-place by move

    virtual void construct( T* ptr, const T& copy );
      // Construct a T object in-place by copy

    virtual void destruct( T* ptr );
      // Call the destructor on an object
};

// Static variables instantiation
template<typename T>
int CountingAllocator<T>::d_total_allocation_count = 0;

template<typename T>
int CountingAllocator<T>::d_total_release_count = 0;


//
// CONSTRUCTORS
//

template<typename T>
inline
CountingAllocator<T>::CountingAllocator()
    : d_allocation_count( 0 ), d_release_count( 0 )
{
}

template<typename T>
inline
CountingAllocator<T>::CountingAllocator( const CountingAllocator<T>& copy )
    : d_allocation_count( copy.d_allocation_count ),
      d_release_count( copy.d_release_count )
{
}


//
// DESTRUCTOR
//

template<typename T>
inline
CountingAllocator<T>::~CountingAllocator()
{
}


//
// OPERATORS
//

template<typename T>
inline
CountingAllocator<T>&
CountingAllocator<T>::operator=( const CountingAllocator<T>& allocator )
{
    d_allocation_count = allocator.d_allocation_count;
    d_release_count = allocator.d_release_count;

    return *this;
}


//
// MEMBER FUNCTIONS
//

template<typename T>
inline
T* CountingAllocator<T>::get( int count )
{
    assert( count > 0 );

    d_allocation_count += count;
    d_total_allocation_count += count;

    return DefaultAllocator<T>::get( count );
}

template<typename T>
inline
void CountingAllocator<T>::release( T* ptr, int count )
{
    assert( ptr != nullptr );
    assert( count > 0 );

    d_release_count += count;
    d_total_release_count += count;

    DefaultAllocator<T>::release( ptr, count );
}

template<typename T>
inline
void CountingAllocator<T>::construct( T* ptr, T&& copy )
{
    ptr = new T( copy );
}

template<typename T>
inline
void CountingAllocator<T>::construct( T* ptr, const T& copy )
{
    ptr = new T( copy );
}

template<typename T>
inline
void CountingAllocator<T>::destruct( T* ptr )
{
    delete ptr;
}


//
// ACCESSORS
//

template<typename T>
inline
int const CountingAllocator<T>::getAllocationCount()
{
    return d_allocation_count;
}

template<typename T>
inline
int const CountingAllocator<T>::getReleaseCount()
{
    return d_release_count;
}

template<typename T>
inline
int const CountingAllocator<T>::getOutstandingCount()
{
    return d_allocation_count - d_release_count;
}

template<typename T>
inline
int CountingAllocator<T>::getTotalAllocationCount()
{
    return d_total_allocation_count;
}

template<typename T>
inline
int CountingAllocator<T>::getTotalReleaseCount()
{
    return d_total_release_count;
}

template<typename T>
inline
int CountingAllocator<T>::getTotalOutstandingCount()
{
    return d_total_allocation_count - d_total_release_count;
}


//
// FREE OPERATORS
//

template<class T>
inline
std::ostream&
operator<<( std::ostream& stream, const CountingAllocator<T> allocator )
{
    return stream << "{ "
        << "\"allocationCount\": " << allocator.getAllocationCount() << ", "
        << "\"releaseCount\": "    << allocator.getReleaseCount()
        << " }";
}

} // End sgdm namespace
} // End StevensDev namespace

#endif // INCLUDED_COUNTING_ALLOCATOR

