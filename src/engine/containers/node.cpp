//
// File: node.cpp
// Author: Barbara Crepeau
//

#include "node.h"

namespace StevensDev
{
namespace sgdc
{

//
// CONSTRUCTORS
//

Node::Node()
    : d_key(), d_index( -1 ), d_children()
{
}

Node::Node( const char& key )
    : d_key( key ), d_index ( -1 ), d_children()
{
}

Node::Node( const Node& copy )
    : d_key( copy.d_key ), d_index( copy.d_index ),
      d_children( copy.d_children )
{
}

Node::Node( Node&& move )
    : d_key( move.d_key ), d_index( move.d_index ),
      d_children( move.d_children )
{
    move.d_key = 0;
    move.d_index = 0;
    move.d_children = 0;
}


//
// DESTRUCTOR
//

Node::~Node()
{
}


//
// OPERATORS
//

Node& Node::operator=( const Node& node )
{
    d_key = node.d_key;
    d_index = node.d_index;
    d_children = node.d_children;

    return *this;
}


//
// ACCESSORS
//

const char Node::key() const
{
    return d_key;
}

const int Node::index() const
{
    return d_index;
}

DynamicArray<Node*> Node::children() const
{
    return d_children;
}


//
// MUTATORS
//

void Node::setIndex( int index )
{
    if (index < -1)
    {
        index = -1;
    }

    d_index = index;
}


//
// MEMBER FUNCTION
//

Node* Node::lookUp( const std::string& key )
{
    return lookUp( key, 0 );
}

Node* Node::lookUp( const std::string& key, int level )
{
    Node *node = findChild( key[level] );

    if (!node)
    {
        return nullptr;
    }

    if ( level >= key.length() - 1 && node->hasValue() )
    {
        return node;
    }
    else
    {
        return node->lookUp( key, level + 1);
    }
}

Node* Node::findChild( const char c )
{
    for ( int i = 0; i < d_children.length(); i++ )
    {
        Node *current = d_children[i];

        if ( current->key() == c )
        {
            return current;
        }
    }

    return 0;
}

Node* Node::childAt( int index ) const
{
    return d_children[index];
}

bool Node::hasValue() const
{
    return ( d_index >= 0 );
}


bool Node::isFree() const
{
    return !( hasValue() || d_children.length() > 0 );
}

void Node::print( int level )
{
    print( level, false );
}
void Node::remove( const char c )
{
    for ( int i = 0; i < d_children.length(); i++ )
    {
        Node *current = d_children[i];

        if ( current->key() == c )
        {
            d_children.removeAt( i );
            return;
        }
    }
}

void Node::addChild( Node* child )
{
    d_children.push( child );
}

void Node::print( int level, bool last )
{
    for ( int i = 1; i < level; i++)
    {
        std::cout << "    ";
    }

    if ( level > 0 )
    {
        if ( last )
        {
            std::cout << "└── ";
        }
        else
        {
            std::cout << "├── ";
        }
    }

    std::cout << d_key << " (" << d_index << ")" << std::endl;

    for ( int i = 0; i < d_children.length(); i++ )
    {
        d_children[i]->print( level + 1, i == d_children.length() - 1 );
    }
}


//
// FREE OPERATORS
//

template<class T>
inline std::ostream&
operator<<( std::ostream& str, const Node node )
{
    str << "{ " << std::endl
        << "key: \"" << node.key() << "\", " << std::endl
        << "index: \"" << node.index() << "\", " << std::endl
        << "children: [";

    for ( int i = 0; i < node.children().length(); i++ )
    {
        if ( i > 0)
        {
            str << ", ";
        }
        str << node.childAt( i );
    }

    str << "]" << std::endl
        << "}" << std::endl;

    return str;

}

} // End sgdc namespace
} // End StevensDev namespace
