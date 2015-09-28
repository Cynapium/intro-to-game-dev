// node.h

//#ifndef INCLUDED_NODE
//# define INCLUDED_NODE

#include "containers/dynamic_array.h"

namespace StevensDev
{
namespace sgdc
{

class Node
{
  private:
    char                    d_key;
      // The key used for this node

    int                     d_index;
      // Index of the pair <string key, T value> in corresponding Map

    DynamicArray<Node*>     d_children;
      // Children of this node
      // TODO: Make a not-dynamic array of 26 cells.


  public:

    // CONSTRUCTORS

    Node();
      // Default constructor

    Node( const char& key );
      // Constructor with key

    Node( const Node& copy );
      // Copy constructor

    Node( Node&& move );
      // Move constructor

    
    // DESTRUCTOR

    virtual ~Node();


    // OPERATORS

    Node&               operator=( const Node& node );
      // Copy assignment operator


    // ACCESSORS

    const char          key() const;
      // Return the key

    const int           index() const;
      // Return the index value

    DynamicArray<Node*> children() const;
      // Return the list of children for this node


    // MUTATORS

    void                setIndex( int index );
      // Set the index: It can be update to match the corresponding Map.


    // MEMBER FUNCTIONS

    Node*               lookUp( const std::string& key );
      // Search the node matching with this key
      // Call lookUp( key, level ) with level = 0.

    Node*               lookUp( const std::string& key, int level );
      // Search the node matching with this key, keeping track of the level

    Node*               findChild( const char c );
      // Find the child of the current node which has 'c' as key

    Node*               childAt( int index ) const;
      // Return the child at a given index

    bool                hasValue() const;
      // Return true if this node represents a value
      // If yes, the index will indicate where is the key/value in the Map

    bool                isFree() const;
      // Return true if this node has no value and no children

    void                remove( const char c );
      // Remove the children with this key

    void                addChild( Node* child );
      // Add a child to the node

    void                print( int level );
      // Call print( int level, bool last ) with last = false

    void                print( int level, bool last );
      // Pretty print the node and its children

};

} // End sgdc namespace
} // End StevensDev namespace

//#endif // INCLUDED_NODE
