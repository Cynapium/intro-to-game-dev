// box_collider.cpp

#include "box_collider.h"

namespace StevensDev
{
namespace sgds
{

//
// CONSTRUCTORS
//

BoxCollider::BoxCollider( int x, int y, int width, int height )
    : ICollider( x, y, width, height )
{
}

BoxCollider::BoxCollider( const BoxCollider& box )
    : ICollider( box.d_bounds, box.d_flags )
{
}

BoxCollider::BoxCollider( BoxCollider&& box )
    : ICollider( box.d_bounds, box.d_flags )
{
}


//
// OPERATORS
//

BoxCollider&
BoxCollider::operator=( const BoxCollider& copy )
{
}

BoxCollider&
BoxCollider::operator=( BoxCollider&& move )
{
}


//
// MEMBER FUNCTIONS
//

bool
BoxCollider::canCollide( unsigned short flags ) const
{
    return true; // FIXME
}

bool
BoxCollider::doesCollide( const RectangleBounds& rectangle )
{
    return true; // FIXME
}


} // end sgds namespace
} // end StevensDev namespace
