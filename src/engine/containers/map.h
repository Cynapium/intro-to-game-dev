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
    int                 index;
    //
    DynamicArray< Node<T>* > children;
    //

    Node()
        : key(), index( -1 ), children()
    {
    }

    void addChild( Node<T>* child )
    {
        children.push( child );
    }

    // FIXME: My code is ugly.
    void print( int level, bool last = false )
    {
        for ( int i = 1; i < level; i++)
            std::cout << "    ";

        if ( level > 0 )
            if ( last )
                std::cout << "└── ";
            else
                std::cout << "├── ";

        std::cout << key << std::endl;

        for ( int i = 0; i < children.getLength(); i++ )
        {
            children[i]->print( level + 1, i == children.getLength() - 1 );
        }

    }
};



///////////////////////////////////////////////////////////////////////////////

template<typename T>
class Map
{
  private:

    Node<T>*            d_trie;
    // Root node of the trie containing keys & values

    DynamicArray<std::string>     d_keys;
    // Keys of the map

    DynamicArray<T>     d_values;
    // Values of the map


    // MEMBER FUNCTIONS

    Node<T>*            lookUp( const std::string& key );
      //

    Node<T>*            findChild( Node<T>* node, const char c );
      //

    Node<T>*            createEntry( const std::string );
      // Create an empty entry in the map and return link to the Node in tries


  public:

    // FIXME: Clean that
    void print() { d_trie->print( 0 ); }


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

    const DynamicArray<std::string>& keys() const;
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

        if ( current->key == c )
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

        if ( current->index >= 0 )
            return current;
        else
            return nullptr;
    }
}

template<typename T>
inline
Node<T>* Map<T>::createEntry( const std::string key )
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

    // Update current node
    current->index = d_values.getLength();

    // Fill arrays with default values
    d_values.push( 0 );
    d_keys.push( key );

    return current;
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

    return *this;
}

template<typename T>
inline
T& Map<T>::operator[]( const std::string& key )
{
    Node<T>*    node = lookUp( key );

    // If the value does not exist, create an entry with default value
    if ( !node )
        node = createEntry( key );

    return d_values[node->index];
}

template<typename T>
inline
const T Map<T>::operator[]( const std::string& key ) const
{
    Node<T>*    node = lookUp( key );
    std::cout << "const" << std::endl; // XXX TO REMOVE

    // If the value does not exist, create an entry with default value
    if ( !node )
        node = createEntry( key );

    return d_values[node->index];
}


// MEMBER FUNCTIONS

template<typename T>
inline
bool Map<T>::has( const std::string& key )
{
    Node<T>*        node = lookUp( key );

    if ( node )
    {
        return true;
    }

    return false;
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
