// map.h

#ifndef INCLUDED_MAP
# define INCLUDED_MAP

#include <cstddef>
#include "../memory/iallocator.h"
#include "dynamic_array.h"

namespace StevensDev
{
namespace sgdc
{

template<typename T>
struct Node
{
    char                key;
    //
    T                   value;
    //
    bool                hasValue;
    //
    DynamicArray< Node<T>* > children;
    //

    Node()
        : key(), value(), hasValue( false ), children()
    {
    }

    void addChild( Node<T>* child )
    {
        children.push( child );
    }
};



///////////////////////////////////////////////////////////////////////////////

template<typename T>
class Map
{
  private:

    Node<T>*            d_trie;
    // Root node of the trie containing keys & values

    DynamicArray<T>     d_keys;
    // Keys of the map

    DynamicArray<T>     d_values;
    // Values of the map


    // MEMBER FUNCTIONS

    Node<T>*            lookUp( const std::string& key );
      //

    Node<T>*            findChild( Node<T>* node, const char c );
      //



  public:

    void                insert( const std::string, T& value );
    void                insert( const std::string );
    // CONSTRUCTORS

    Map();
      // Default constructor

    Map( IAllocator<T> *alloc );
      // Constructor

    Map( const Map<T>& map );
      // Copy constructor

    Map( Map<T>&& map );
      // Move constructor


    // DESTRUCTORS

    virtual ~Map();
      // Destructor


    // OPERATORS

    Map&                operator=( const Map<T>& map );
      // Copy assignment operator

    T&                  operator[]( const std::string& key );
      // Mutable

    const T             operator[]( const std::string& key ) const;
      // No mutation


    // MEMBER FUNCTIONS

    bool                has( const std::string& key );
      // Determines if a key exists in the map

    T                   remove( const std::string& key );
      // Removes a key and its value

    const DynamicArray<T>& keys() const;
      // Retrieves all keys

    const DynamicArray<T>& values() const;
      // Retrieves all values
};


// PRIVATE MEMBER FUNCTIONS
template<typename T>
inline
Node<T>* Map<T>::findChild( Node<T>* node, const char c )
{
    for ( int i = 0; i < node->children.getLength(); i++ )
    {
        Node<T>         *current = node->children[i];

        if ( current->hasValue && current->key == c )
        {
            return current;
        }
    }

    return 0;
}

template<typename T>
inline
Node<T>* Map<T>::lookUp( const std::string& key )
{
    Node<T>             *current = d_trie;

    while ( current )
    {
        for ( int i = 0; i < key.length(); i++ )
        {

            current = findChild( current, key[i] );

            if (!current)
            {
                return nullptr;
            }
        }

        if ( current->hasValue )
            return current;
        else
            return nullptr;
    }
}

// FIXME: Duplicate with insert( string, value ) so find a way to fix that.
template<typename T>
inline
void Map<T>::insert( const std::string key )
{
    Node<T>             *current = d_trie;

    for ( int i = 0; i < key.length(); i++ )
    {
        Node<T>         *child = findChild( current, key[i] );
        
        if ( child )
        {
            current = child;
        }
        else
        {
            child = new Node<T>();
            child->key = key[i];
            current->children.push( child );
            current = child;
        }
    }
}

template<typename T>
inline
void Map<T>::insert( const std::string key, T& value )
{
    Node<T>             *current = d_trie;

    for ( int i = 0; i < key.length(); i++ )
    {
        Node<T>         *child = findChild( current, key[i] );
        
        if ( child )
        {
            current = child;
        }
        else
        {
            child = new Node<T>();
            child->key = key[i];
            current->children.push( child );
            current = child;
        }
    }

    if ( value )
    {
        current->hasValue = true;
        current->value = value;
    }
}


// CONSTRUCTORS

template<typename T>
inline
Map<T>::Map()
    : d_trie(), d_keys(), d_values()
{
    d_trie = new Node<T>();
}

template<typename T>
inline
Map<T>::Map( IAllocator<T> *alloc )
    : d_trie(), d_keys( alloc ), d_values( alloc )
{
    d_trie = new Node<T>();
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


// DESTRUCTORS

template<typename T>
inline
Map<T>::~Map()
{
}


// OPERATORS

template<typename T>
inline
Map<T>& Map<T>::operator=( const Map& map )
{
    d_trie = map.d_trie;
    d_keys = map.d_keys;
    d_values = map.d_values;
}

template<typename T>
inline
T& Map<T>::operator[]( const std::string& key )
{
    Node<T>*    node = lookUp( key );

    // If the value does not exist, create an entry with default value
    if ( !node )
        insert( key );

    return node->value;
}

template<typename T>
inline
const T Map<T>::operator[]( const std::string& key ) const
{
    Node<T>*    node = lookUp( key );

    // If the value does not exist, create an entry with default value
    if ( !node )
        insert( key );

    return node->value;
}


// MEMBER FUNCTIONS

template<typename T>
inline
bool Map<T>::has( const std::string& key )
{
    return lookUp( key )->value;
}

template<typename T>
inline
T Map<T>::remove( const std::string& key )
{
    // TODO
    return nullptr;
}

template<typename T>
inline
const DynamicArray<T>& Map<T>::keys() const
{
    return d_keys;
}

template<typename T>
inline
const DynamicArray<T>& Map<T>::values() const
{
    return d_values;
}


// FREE OPERATORS

template<class T>
inline std::ostream&
operator<<( std::ostream& stream, const Map<T> map )
{
    return stream << "{ Map }";
}


} // End sgdc namespace
} // End StevensDev namespace

#endif // INCLUDED_MAP
