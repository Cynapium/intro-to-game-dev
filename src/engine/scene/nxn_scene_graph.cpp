// nxn_scene_graph.cpp

#include "nxn_scene_graph.h"

namespace StevensDev
{
namespace sgds
{

//
// CONSTRUCTORS
//

NxNSceneGraph::NxNSceneGraph( float dimensions, int divisions )
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

float
NxNSceneGraph::dimensions()
{
    return d_dimensions;
}

int
NxNSceneGraph::divisions()
{
    return d_divisions;
}

sgdc::DynamicArray<ICollider*>
NxNSceneGraph::colliders()
{
    return d_colliders;
}




//
// MEMBER FUNCTIONS
//

void
NxNSceneGraph::addCollider( ICollider *collider )
{
    d_colliders.push( collider );
}

void
NxNSceneGraph::removeCollider( ICollider *collider )
{
    // TODO
}

sgdc::DynamicArray<ICollider*>
NxNSceneGraph::find( float x, float y, float w, float h )
{
    // TODO
    return d_colliders;
}

sgdc::DynamicArray<ICollider*>
NxNSceneGraph::find( float x, float y, float w, float h, unsigned short flags )
{
    // TODO
    return d_colliders;
}

sgdc::DynamicArray<ICollider*>
NxNSceneGraph::find( const RectangleBounds &bounds )
{
    // TODO
    return d_colliders;
}

sgdc::DynamicArray<ICollider*>
NxNSceneGraph::find( const RectangleBounds &bounds, unsigned short flags )
{
    // TODO
    return d_colliders;
}

sgdc::DynamicArray<ICollider*>
NxNSceneGraph::find( const ICollider *collider )
{
    // TODO
    return d_colliders;
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
