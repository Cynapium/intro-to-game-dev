// actor.cpp

#include "scene/iactor.h"
#include "scene/box_collider.h"
#include "scene/scene.h"
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
IActor::setPosition( int x, int y )
{
    d_sprite->setPosition( x, y );
    d_collider->bounds().setPosition( x, y );
}

void
IActor::move( float x, float y )
{
    Scene        scene = Scene::inst();
    const int    x_current = d_collider->bounds().x();
    const int    y_current = d_collider->bounds().y();

    // Check if we can move
    if ( x_current + x >= 0 &&
         x_current + x + d_sprite->width() < scene.graph()->dimensions() )
    {
        d_sprite->move( x, 0 );
    }

    if ( y_current + y >= 0 &&
         y_current + y + d_sprite->height() < scene.graph()->dimensions() )
    {
        d_sprite->move( 0, y );
    }

    d_collider->bounds().setPosition( d_sprite->getPositionX(), d_sprite->getPositionY() );
}


} // end sgds namespace
} // end StevensDev namespace
