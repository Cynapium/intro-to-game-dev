// maps.h

#ifndef INCLUDED_MAPS
# define INCLUDED_MAPS

#include "dynamic_array.h"

namespace StevensDev
{
namespace sgdc
{

typedef DynamicArray<T> DynArr

template<typename T>
class Maps
{
  private:

      DynamicArray<T>   d_keys;
        // Keys of the map

      DynamicArray<T>   d_values;
        // Values of the map
    
  public:


    // CONSTRUCTORS

    Maps();
      // Default constructor

    Maps( IAllocator *alloc );
      // Constructor

    Maps( const Maps& maps );
      // Copy constructor

    Maps( const Maps&& maps);
      // Move constructor

    
    // DESTRUCTORS

    virtual ~Maps();
      // Destructor


    // OPERATORS

    Maps&               operator=( const Maps& maps );
      // Copy assignment operator

    T                   operator[]( const std::string& key );
      // Mutable

    const T             operator[]( const std::string& key ) const;
      // No mutation


    // MEMBER FUNCTIONS

    bool                has( const std::string& key );
      // Determines if a key exists in the map

    T                   remove( const std::string& key );
      // Removes a key and its value

    const DynArr&       keys() const;
      // Retrieves all keys

    const DynArr&       values() const;
      // Retrieves all values
};

// CONSTRUCTORS

template<typename T>
inline
Maps()
    : d_keys(), d_values()
{
}

template<typename T>
inline
Maps( IAllocator *alloc )
    : d_keys( alloc ), d_values( alloc )
{
}

template<typename T>
inline
Maps( const Maps& maps )
    : d_keys( maps.d_keys ), d_values( maps.d_values )
{
}

template<typename T>
inline
Maps( const Maps&& maps)
    : d_keys( maps.d_keys ), d_values( maps.d_values )
{
    maps.d_key = 0;
    maps.d_values = 0;
}


// DESTRUCTORS

template<typename T>
inline
virtual ~Maps()
{
    delete d_keys;
    delete d_values;
}


// OPERATORS

template<typename T>
inline
Maps& operator=( const Maps& maps )
{
    d_keys = maps.d_keys;
    d_values = maps.d_values;
}

template<typename T>
inline
T operator[]( const std::string& key )
{
    if (
}

template<typename T>
inline
const T operator[]( const std::string& key ) const
{
}


// MEMBER FUNCTIONS

template<typename T>
inline
bool has( const std::string& key )
{
}

template<typename T>
inline
T remove( const std::string& key )
{
}

template<typename T>
inline
const DynArr& keys() const
{
}

template<typename T>
inline
const DynArr& values() const
{
}


// FREE OPERATORS

template<class T>
inline std::ostream&
operator<<( std::ostream& stream, const Maps<T> maps )
{
    return stream << "{ Maps }";
}


} // End sgdc namespace
} // End StevensDev namespace

#endif // INCLUDED_MAPS
