//
// File: rectangle_bounds.cpp
// Author: Barbara Crepeau
//

#include "rectangle_bounds.h"

namespace StevensDev
{
namespace sgds
{

//
// CONSTRUCTORS
//

RectangleBounds::RectangleBounds()
    : d_x( 0 ), d_y( 0 ), d_width( 0 ), d_height( 0 )
{
}

RectangleBounds::RectangleBounds( float x, float y, float width, float height )
    : d_x( x ), d_y( y ), d_width( width ), d_height( height )
{
}

RectangleBounds::RectangleBounds( const RectangleBounds& rectangle )
    : d_x( rectangle.d_x ), d_y( rectangle.d_y ),
      d_width( rectangle.d_width ), d_height( rectangle.d_height )
{
}

RectangleBounds::RectangleBounds( RectangleBounds&& rectangle )
    : d_x( rectangle.d_x ), d_y( rectangle.d_y ),
      d_width( rectangle.d_width ), d_height( rectangle.d_height )
{
    // Reset rectangle
    rectangle.d_x = 0;
    rectangle.d_y = 0;
    rectangle.d_width = 0;
    rectangle.d_height = 0;
}


//
// DESTRUCTOR
//

RectangleBounds::~RectangleBounds()
{
}


//
// ACCESSORS
//

const float
RectangleBounds::x() const
{
    return d_x;
}

const float
RectangleBounds::y() const
{
    return d_y;
}

const float
RectangleBounds::width() const
{
    return d_width;
}

const float
RectangleBounds::height() const
{
    return d_height;
}


//
// MUTATORS
//

void
RectangleBounds::setX( float x )
{
    d_x = x;
}

void
RectangleBounds::setY( float y )
{
    d_y = y;
}

void
RectangleBounds::setWidth( float w )
{
    d_width = w;
}

void
RectangleBounds::setHeight( float h )
{
    d_height = h;
}

void
RectangleBounds::setPosition( float x, float y )
{
    setX( x );
    setY( y );
}

void
RectangleBounds::setDimensions( float w, float h )
{
    setWidth( w );
    setHeight( h );
}



//
// OPERATORS
//

RectangleBounds&
RectangleBounds::operator=( const RectangleBounds& rectangle )
{
    // Copy content of rectangle into this one
    d_x = rectangle.d_x;
    d_y = rectangle.d_y;
    d_width = rectangle.d_width;
    d_height = rectangle.d_height;

    return *this;
}

RectangleBounds&
RectangleBounds::operator=( RectangleBounds&& rectangle )
{
    // Copy content of rectangle into this one
    d_x = rectangle.d_x;
    d_y = rectangle.d_y;
    d_width = rectangle.d_width;
    d_height = rectangle.d_height;

    // Reset rectangle
    rectangle.d_x = 0;
    rectangle.d_y = 0;
    rectangle.d_width = 0;
    rectangle.d_height = 0;
}

const bool
RectangleBounds::doesCollide( const RectangleBounds& candidate ) const
{
    // If one of them has has a width and a height of zero, then it does not
    // really exist on the plan and cannot collide.
    if ( ( d_width == 0 && d_height == 0 ) ||
         ( candidate.d_width == 0 && candidate.d_height == 0 ) )
    {
        return false;
    }

    // Define points for the first rectangle
    float rec1_x1 = d_x;
    float rec1_y1 = d_y;
    float rec1_x2 = d_x + d_width;
    float rec1_y2 = d_y + d_height;

    // Define points for the second rectangle
    float rec2_x1 = candidate.d_x;
    float rec2_y1 = candidate.d_y;
    float rec2_x2 = candidate.d_x + candidate.d_width;
    float rec2_y2 = candidate.d_y + candidate.d_height;

    // Return the result of the collision
    return ( rec1_x1 < rec2_x2 && rec1_x2 > rec2_x1 &&
             rec1_y1 < rec2_y2 && rec1_y2 > rec2_y1 );
}

} // End sgds namespace
} // End StevensDev namespace
