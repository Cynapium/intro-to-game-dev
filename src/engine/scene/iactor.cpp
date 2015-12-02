// actor.cpp

#include "scene/iactor.h"
#include "input/input.h"

namespace StevensDev
{
namespace sgds
{

//
// CONSTRUCTORS
//

IActor::IActor( std::string name, const sf::Texture &texture )
    : d_name( name ), d_sprite( texture )
{
}

IActor::IActor( const IActor& actor )
    : d_name( actor.d_name ), d_sprite( actor.d_sprite )
{
}

IActor::IActor( IActor&& actor )
    : d_name( actor.d_name ), d_sprite( actor.d_sprite )
{
    // TODO set actor attributes to null
}


//
// OPERATORS
//

IActor&
IActor::operator=( const IActor &copy )
{
    d_name = copy.d_name;
    d_sprite = copy.d_sprite;
}

IActor&
IActor::operator=( IActor &&move )
{
    d_name = move.d_name;
    d_sprite = move.d_sprite;

    move.d_name = "";
}


//
// ACCESSORS
//
std::string
IActor::name()
{
    return d_name;
}

sgdr::RenderableSprite&
IActor::sprite()
{
    return d_sprite;
}

sgds::ICollider*
IActor::collider()
{
    return d_collider;
}



//
// MEMBER FUNCTIONS
//
/*

void
IActor::preTick()
{
}

void
IActor::tick( float dts )
{
    sgdi::Input                 &in = sgdi::Input::inst();

    if ( in.isDown( sgdi::KEY_Right ) )
        move( 2, 0 );
    if ( in.isDown( sgdi::KEY_Left ) )
        move( -2, 0 );
    if ( in.isDown( sgdi::KEY_Up ) )
        move( 0, -2 );
    if ( in.isDown( sgdi::KEY_Down ) )
        move( 0, 2 );
}

void
IActor::postTick()
{
}
*/

} // end sgds namespace
} // end StevensDev namespace
