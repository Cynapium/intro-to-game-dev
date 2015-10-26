// rectangle_bounds.cpp

#include "rectangle_bounds.h"

namespace StevensDev
{
namespace sgds
{

//
// CONSTRUCTORS
//

RectangleBounds::RectangleBounds()
    : RectangleBounds( 0, 0, 0, 0 )
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
RectangleBounds::setX( float xval )
{
    d_x = xval;
}

void
RectangleBounds::setY( float yval )
{
    d_y = yval;
}

void
RectangleBounds::setWidth( float wval )
{
    d_width = wval;
}

void
RectangleBounds::setHeight( float hval )
{
    d_height = hval;
}

void
RectangleBounds::setPosition( float xval, float yval )
{
    setX( xval );
    setY( yval );
}

void
RectangleBounds::setDimensions( float wval, float hval )
{
    setWidth( wval );
    setHeight( hval );
}



//
// OPERATORS
//

RectangleBounds&
RectangleBounds::operator=( const RectangleBounds& rectangle )
{
    // FIXME
    d_x = rectangle.d_x;
    d_y = rectangle.d_y;
    d_width = rectangle.d_width;
    d_height = rectangle.d_height;

    return *this;
}

RectangleBounds&
RectangleBounds::operator=( RectangleBounds&& rectangle )
{
    // FIXME
    d_x = rectangle.d_x;
    d_y = rectangle.d_y;
    d_width = rectangle.d_width;
    d_height = rectangle.d_height;
    rectangle.d_x = 0;
    rectangle.d_y = 0;
    rectangle.d_width = 0;
    rectangle.d_height = 0;
}

bool
RectangleBounds::doesCollide( const RectangleBounds& candidate )
{
    if ( ( d_width == 0 && d_height == 0 ) || 
         ( candidate.d_width == 0 && candidate.d_height == 0 ) )
        return false;

    float           rec1_x1 = d_x;
    float           rec1_y1 = d_y;
    float           rec1_x2 = d_x + d_width;
    float           rec1_y2 = d_y + d_height;

    float           rec2_x1 = candidate.d_x;
    float           rec2_y1 = candidate.d_y;
    float           rec2_x2 = candidate.d_x + candidate.d_width;
    float           rec2_y2 = candidate.d_y + candidate.d_height;

    return ( rec1_x1 < rec2_x2 && rec1_x2 > rec2_x1 &&
             rec1_y1 < rec2_y2 && rec1_y2 > rec2_y1 );
}

} // End sgds namespace
} // End StevensDev namespace
