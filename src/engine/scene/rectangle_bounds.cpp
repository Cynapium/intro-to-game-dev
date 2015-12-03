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

RectangleBounds::RectangleBounds( int x, int y, int width, int height )
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

const int
RectangleBounds::x() const
{
    return d_x;
}

const int
RectangleBounds::y() const
{
    return d_y;
}

const int
RectangleBounds::width() const
{
    return d_width;
}

const int
RectangleBounds::height() const
{
    return d_height;
}


//
// MUTATORS
//

void
RectangleBounds::setX( int x )
{
    d_x = x;
}

void
RectangleBounds::setY( int y )
{
    d_y = y;
}

void
RectangleBounds::setWidth( int w )
{
    d_width = w;
}

void
RectangleBounds::setHeight( int h )
{
    d_height = h;
}

void
RectangleBounds::setPosition( int x, int y )
{
    setX( x );
    setY( y );
}

void
RectangleBounds::setDimensions( int w, int h )
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
    int rec1_x1 = d_x;
    int rec1_y1 = d_y;
    int rec1_x2 = d_x + d_width;
    int rec1_y2 = d_y + d_height;

    // Define points for the second rectangle
    int rec2_x1 = candidate.d_x;
    int rec2_y1 = candidate.d_y;
    int rec2_x2 = candidate.d_x + candidate.d_width;
    int rec2_y2 = candidate.d_y + candidate.d_height;

    // Return the result of the collision
    return ( rec1_x1 < rec2_x2 && rec1_x2 > rec2_x1 &&
             rec1_y1 < rec2_y2 && rec1_y2 > rec2_y1 );
}

} // End sgds namespace
} // End StevensDev namespace
