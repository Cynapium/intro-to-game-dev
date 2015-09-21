// node.h

//#ifndef INCLUDED_NODE
//# define INCLUDED_NODE

#include "dynamic_array.h"

namespace StevensDev
{
namespace sgdc
{

class Node
{
  private:
    char                    d_key;
    //
    int                     d_index;
    //
    DynamicArray<Node*>     d_children;
    //

  public:

    // CONSTRUCTORS

    Node();
    Node( const char& key );
    Node( const Node& copy );
    Node( Node&& move );

    
    // DESTRUCTOR

    virtual ~Node();


    // OPERATORS

    Node&               operator=( const Node& node );


    // ACCESSORS

    char                key();
    int                 index();
    DynamicArray<Node*> children();
    Node*               childAt( int index );


    // MUTATORS

    void                setIndex( int index );

    // MEMBER FUNCTIONS

    void addChild( Node* child );
      // Add a child to the node

    void print( int level );
    void print( int level, bool last );
      // Pretty print the node and its children

};

} // End sgdc namespace
} // End StevensDev namespace

//#endif // INCLUDED_NODE
