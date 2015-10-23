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
    // TODO
    return true;
}


} // End sgds namespace
} // End StevensDev namespace
