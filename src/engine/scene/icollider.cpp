//
// File: icollider.cpp
// Author: Barbara Crepeau
//

#include "icollider.h"

namespace StevensDev
{
namespace sgds
{

//
// CONSTRUCTORS
//

ICollider::ICollider( int x, int y, int width, int height )
    : d_bounds( x, y, width, height )
{
}

ICollider::ICollider( RectangleBounds bounds, unsigned short flags )
    : d_bounds( bounds ), d_flags( flags )
{
}


//
// ACCESSORS
//

RectangleBounds&
ICollider::bounds()
{
    return d_bounds;
}

const RectangleBounds&
ICollider::bounds() const
{
    return d_bounds;
}

unsigned short
ICollider::flags() const
{
    return d_flags;
}


//
// MUTATOR
//

void
ICollider::setFlags( unsigned short flags )
{
    d_flags = flags;
}

} // end sgds namespace
} // end StevensDev namespace

#include "icollider.h"
