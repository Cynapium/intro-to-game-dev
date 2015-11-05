//
// File: map.h
// Author: Barbara Crepeau
//
// Declare Map templated class and its functions
//

#ifndef INCLUDED_MAP
# define INCLUDED_MAP

#include <cstddef>
#include "containers/dynamic_array.h"
#include "containers/node.h"
#include "memory/iallocator.h"

namespace StevensDev
{
namespace sgdc
{

// Represents a map which stores elements with a key, using a trie
template<typename T>
class Map
{
  private:

    Node*                       d_trie;
      // Root node of the trie containing keys & values

    DynamicArray<std::string>   d_keys;
      // Keys of the map

    DynamicArray<T>             d_values;
      // Values of the map


    // MEMBER FUNCTIONS

    Node*               createEntry( const std::string );
      // Create an empty entry in the map and return link to the Node in tries


  public:

    // CONSTRUCTORS

    Map();
      // Default constructor

    Map( sgdm::IAllocator<T> *alloc );
      // Constructor

    Map( const Map<T>& map );
      // Copy constructor

    Map( Map<T>&& map );
      // Move constructor


    // DESTRUCTORS

    virtual ~Map();
      // Destroy all elements


    // OPERATORS

    Map& operator=( const Map<T>& map );
      // Copy assignment operator

    T& operator[]( const std::string& key );
      // Mutable

    const T operator[]( const std::string& key ) const;
      // No mutation


    // ACCESSORS

    const DynamicArray<std::string>& keys() const;
      // Retrieves all keys

    const DynamicArray<T>& values() const;
      // Retrieves all values

    const unsigned int length() const;
      // Return the number of elements in the graph


    // MEMBER FUNCTIONS

    bool has( const std::string& key );
      // Determines if a key exists in the map

    bool remove( Node* node, const std::string& key, int l );
    T remove( const std::string& key );
      // Removes a key and its value

    void print();
      // Print function for debug purpose
};


//
// PRIVATE MEMBER FUNCTIONS
//

template<typename T>
inline
Node* Map<T>::createEntry( const std::string key )
{
    Node *current = d_trie;

    for ( int i = 0; i < key.length(); i++ )
    {
        Node *child = current->findChild( key[i] );

        if ( child )
        {
            current = child;
        }
        else
        {
            child = new Node( key[i] );
            current->addChild( child );
            current = child;
        }
    }

    // Update current node
    current->setIndex( d_values.length() );

    // Fill arrays with default values
    T t;

    d_values.push( t );
    d_keys.push( key );

    return current;
}


//
// CONSTRUCTORS
//

template<typename T>
inline
Map<T>::Map()
    : d_trie(), d_keys(), d_values()
{
    d_trie = new Node();
}

template<typename T>
inline
Map<T>::Map( sgdm::IAllocator<T> *alloc )
    : d_trie(), d_keys( alloc ), d_values( alloc )
{
    d_trie = new Node();
}

template<typename T>
inline
Map<T>::Map( const Map<T>& map )
    : d_trie( map.d_trie ), d_keys( map.d_keys ), d_values( map.d_values )
{
}

template<typename T>
inline
Map<T>::Map( Map<T>&& map )
    : d_trie( map.d_trie), d_keys( map.d_keys ), d_values( map.d_values )
{
    map.d_trie = 0;
    map.d_key = 0;
    map.d_values = 0;
}


//
// DESTRUCTORS
//

template<typename T>
inline
Map<T>::~Map()
{
    // FIXME
    //delete d_trie;
}


//
// OPERATORS
//

template<typename T>
inline
Map<T>& Map<T>::operator=( const Map& map )
{
    d_trie = map.d_trie;
    d_keys = map.d_keys;
    d_values = map.d_values;

    return *this;
}

template<typename T>
inline
T& Map<T>::operator[]( const std::string& key )
{
    Node*    node = d_trie->lookUp( key );

    // If the value does not exist, create an entry with default value
    if ( !node )
    {
        node = createEntry( key );
    }

    return d_values[node->index()];
}

template<typename T>
inline
const T Map<T>::operator[]( const std::string& key ) const
{
    Node*    node = d_trie->lookUp( key );

    return d_values[node->index()];
}


//
// ACCESSORS
//

template<typename T>
inline
const DynamicArray<std::string>& Map<T>::keys() const
{
    return d_keys;
}

template<typename T>
inline
const DynamicArray<T>& Map<T>::values() const
{
    return d_values;
}

template<typename T>
inline
const unsigned int Map<T>::length() const
{
    return d_keys.length();
}


//
// MEMBER FUNCTIONS
//

template<typename T>
inline
bool Map<T>::has( const std::string& key )
{
    return d_trie->lookUp(key);
}

template<typename T>
inline
bool Map<T>::remove( Node* node, const std::string& key, int level )
{
    if ( !node )
    {
        return false;
    }

    if ( level == key.length() )
    {
        if ( !node->hasValue() )
        {
            return false;
        }

        node->setIndex( -1 );
    }
    else
    {
        Node*       child = node->findChild( key[level] );

        if ( remove( child, key, level + 1 ) )
        {
            node->remove( key[level] );
        }
    }

    return node->isFree();
}

template<typename T>
inline
T Map<T>::remove( const std::string& key )
{
    int         index = d_trie->lookUp( key )->index();

    if ( key.length() > 0 )
    {
        remove( d_trie, key, 0 );
    }

    d_keys.removeAt(index);
    return d_values.removeAt(index);
}

template<typename T>
inline
void Map<T>::print()
{
    d_trie->print( 0 );
}


//
// FREE OPERATORS
//

template<class T>
inline std::ostream&
operator<<( std::ostream& str, const Map<T> map )
{
    str << "{ ";

    for ( int i = 0; i < map.values().length(); i++ )
    {
        if ( i > 0)
        {
            str << ", ";
        }
        str << "\"" << map.keys()[i] << "\": " << map.values()[i];
    }

    return str << " }";
}

} // End sgdc namespace
} // End StevensDev namespace

#endif // INCLUDED_MAP
