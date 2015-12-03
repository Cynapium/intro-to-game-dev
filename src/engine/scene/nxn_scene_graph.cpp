//
// File: nxn_scene_graph.cpp
// Author: Barbara Crepeau
//

#include "nxn_scene_graph.h"

namespace StevensDev
{
namespace sgds
{

//
// CONSTRUCTORS
//

NxNSceneGraph::NxNSceneGraph( int dimensions, int divisions )
    : d_dimensions( dimensions ), d_divisions( divisions )
{
}

NxNSceneGraph::NxNSceneGraph( const NxNSceneGraph& copy )
    : d_dimensions( copy.d_dimensions ), d_divisions( copy.d_divisions )
{
}

NxNSceneGraph::NxNSceneGraph( NxNSceneGraph&& move )
    : d_dimensions( move.d_dimensions ), d_divisions( move.d_divisions )
{
    // Reset the other graph
    move.d_dimensions = 0;
    move.d_divisions = 0;
}


//
// DESTRUCTOR
//

NxNSceneGraph::~NxNSceneGraph()
{
}


//
// OPERATORS
//

NxNSceneGraph&
NxNSceneGraph::operator=( const NxNSceneGraph& copy )
{
}

NxNSceneGraph&
NxNSceneGraph::operator=( NxNSceneGraph&& move )
{
}


//
// ACCESSORS
//

const int
NxNSceneGraph::dimensions() const
{
    return d_dimensions;
}

const int
NxNSceneGraph::divisions() const
{
    return d_divisions;
}

sgdc::DynamicArray<ICollider*>
NxNSceneGraph::colliders() const
{
    return d_colliders;
}




//
// MEMBER FUNCTIONS
//

#include <iostream>
void
NxNSceneGraph::addCollider( ICollider *collider )
{
    d_colliders.push( collider );
}

void
NxNSceneGraph::removeCollider( ICollider *collider )
{
    for ( int i = 0; i < d_colliders.length(); i++)
    {
        if ( d_colliders[i] == collider )
        {
            d_colliders.removeAt( i );
            return;
        }
    }
}

sgdc::DynamicArray<ICollider*>
NxNSceneGraph::find( int x, int y, int w, int h )
{
    RectangleBounds rectangle( x, y, w, h );

    return find( rectangle );
}

sgdc::DynamicArray<ICollider*>
NxNSceneGraph::find( int x, int y, int w, int h, unsigned short flags )
{
    RectangleBounds rectangle( x, y, w, h );

    return find( rectangle, flags );
}

sgdc::DynamicArray<ICollider*>
NxNSceneGraph::find( const RectangleBounds &bounds )
{
    sgdc::DynamicArray<ICollider*> array;

    for ( int i = 0; i < d_colliders.length(); i++)
    {
        if ( d_colliders[i]->doesCollide( bounds ) )
        {
            array.push( d_colliders[i] );
        }
    }

    return array;
}

sgdc::DynamicArray<ICollider*>
NxNSceneGraph::find( const RectangleBounds &bounds, unsigned short flags )
{
    sgdc::DynamicArray<ICollider*> array;

    for ( int i = 0; i < d_colliders.length(); i++)
    {
        if ( d_colliders[i]->canCollide( flags ) &&
             d_colliders[i]->doesCollide( bounds ) )
        {
            array.push( d_colliders[i] );
        }
    }

    return array;
}

#include <iostream>

sgdc::DynamicArray<ICollider*>
NxNSceneGraph::find( const ICollider *collider )
{
    sgdc::DynamicArray<ICollider*> array;

    for ( int i = 0; i < d_colliders.length(); i++)
    {
        if ( d_colliders[i] != collider &&
             d_colliders[i]->canCollide( collider->flags() ) &&
             d_colliders[i]->doesCollide( collider->bounds() ) )
        {
            array.push( d_colliders[i] );
        }
    }

    return array;
}

void
NxNSceneGraph::preTick()
{
}

void
NxNSceneGraph::tick( float dts )
{
}

void
NxNSceneGraph::postTick()
{
}

} // end sgds namespace
} // end StevensDev namespace
