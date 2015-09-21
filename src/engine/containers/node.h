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

    const char          key() const;
    const int           index() const;
    DynamicArray<Node*> children() const;

    // MUTATORS

    void                setIndex( int index );

    // MEMBER FUNCTIONS

    Node*               lookUp( const std::string& key );
    Node*               lookUp( const std::string& key, int level );

    Node*               findChild( const char c );
      //
      //

    Node*               childAt( int index ) const;
    bool                hasValue() const;
    bool                isFree() const;
    void                remove( const char c );

    void addChild( Node* child );
      // Add a child to the node

    void print( int level );
    void print( int level, bool last );
      // Pretty print the node and its children

};

} // End sgdc namespace
} // End StevensDev namespace

//#endif // INCLUDED_NODE
