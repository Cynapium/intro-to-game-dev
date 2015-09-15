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

    // CONSTRUCTORS

    CountingAllocator();
      // Instantiate a CountingAllocator

    CountingAllocator( const CountingAllocator<T>& allocator );
      // Copy constructor


    // DESTRUCTOR

    virtual             ~CountingAllocator();


    // OPERATORS

    CountingAllocator&  operator=( const CountingAllocator& copy );
      // Copy assignment operator


    // ACCESSORS

    int const           getAllocationCount();
      // Number of allocations that occured

    int const           getReleaseCount();
      // Number of releases that occured

    int const           getOutstandingCount();
      // Allocations - releases

    static int          getTotalAllocationCount();
      // Number of allocations across instances

    static int          getTotalReleaseCount();
      // Number of releases across instances

    static int          getTotalOutstandingCount();
      // Allocations - releases across instances


    // MEMBER FUNCTIONS

    T*                  get( int count );

    void                release( T* ptr, int count );
};

// Static variables instantiation
template<typename T>
int CountingAllocator<T>::d_total_allocation_count = 0;

template<typename T>
int CountingAllocator<T>::d_total_release_count = 0;


// CONSTRUCTORS

template<typename T>
CountingAllocator<T>::CountingAllocator()
    : d_allocation_count( 0 ), d_release_count( 0 )
{
}

template<typename T>
CountingAllocator<T>::CountingAllocator( const CountingAllocator<T>& copy )
    : d_allocation_count( copy.d_allocation_count ),
      d_release_count( copy.d_release_count )
{
}


// DESTRUCTOR

template<typename T>
CountingAllocator<T>::~CountingAllocator()
{
}


// OPERATORS

template<typename T>
inline CountingAllocator<T>&
CountingAllocator<T>::operator=( const CountingAllocator<T>& allocator )
{
    d_allocation_count = allocator.d_allocation_count;
    d_release_count = allocator.d_release_count;

    return *this;
}


// MEMBER FUNCTIONS
template<typename T>
inline T*
CountingAllocator<T>::get( int count )
{
    if ( count <= 0 )
        return 0;

    d_allocation_count += count;
    d_total_allocation_count += count;

    return DefaultAllocator<T>::get( count );
}

template<typename T>
inline void
CountingAllocator<T>::release( T* ptr, int count )
{
    if ( ptr == 0 || count <= 0 )
        return;

    d_release_count += count;
    d_total_release_count += count;

    DefaultAllocator<T>::release( ptr, count );
}


// ACCESSORS

template<typename T>
inline int const
CountingAllocator<T>::getAllocationCount()
{
    return d_allocation_count;
}

template<typename T>
inline int const
CountingAllocator<T>::getReleaseCount()
{
    return d_release_count;
}

template<typename T>
inline int const
CountingAllocator<T>::getOutstandingCount()
{
    return d_allocation_count - d_release_count;
}

template<typename T>
inline int
CountingAllocator<T>::getTotalAllocationCount()
{
    return d_total_allocation_count;
}

template<typename T>
inline int
CountingAllocator<T>::getTotalReleaseCount()
{
    return d_total_release_count;
}

template<typename T>
inline int
CountingAllocator<T>::getTotalOutstandingCount()
{
    return d_total_allocation_count - d_total_release_count;
}


// FREE OPERATORS

template<class T>
inline std::ostream&
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

