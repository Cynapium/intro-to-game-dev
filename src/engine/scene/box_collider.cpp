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
    return ( d_flags & flags );
}

bool
BoxCollider::doesCollide( const RectangleBounds& rectangle )
{
    return d_bounds.doesCollide( rectangle );
}


} // end sgds namespace
} // end StevensDev namespace
