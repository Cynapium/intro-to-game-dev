// actor.cpp

#include "scene/iactor.h"
#include "scene/box_collider.h"
#include "input/input.h"

namespace StevensDev
{
namespace sgds
{

//
// CONSTRUCTORS
//

IActor::IActor( std::string name, const sf::Texture &texture )
    : d_name( name ),
      d_sprite( new sgdr::RenderableSprite( texture ) ),
      d_collider( new BoxCollider( d_sprite->getPositionX(),
                                   d_sprite->getPositionY(),
                                   d_sprite->width(),
                                   d_sprite->height() ) )
{
}

IActor::IActor( const IActor& actor )
    : d_name( actor.d_name ),
      d_sprite( actor.d_sprite )//,
      //d_collider( actor.collider )
{
}

IActor::IActor( IActor&& actor )
    : d_name( actor.d_name ),
      d_sprite( actor.d_sprite )//,
      //d_collider( actor.d_collider )
{
    // TODO set actor attributes to null
}


//
// OPERATORS
//

IActor&
IActor::operator=( const IActor &actor )
{
    d_name = actor.d_name;
    d_sprite = actor.d_sprite;
}

IActor&
IActor::operator=( IActor &&actor )
{
    d_name = actor.d_name;
    d_sprite = actor.d_sprite;

    actor.d_name = "";
}


//
// ACCESSORS
//
std::string
IActor::name()
{
    return d_name;
}

sgdr::RenderableSprite*
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

void
IActor::move( float x, float y )
{
    d_sprite->move( x, y );
}


} // end sgds namespace
} // end StevensDev namespace
