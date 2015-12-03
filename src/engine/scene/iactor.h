// actor.h

#ifndef INCLUDED_ACTOR
# define INCLUDED_ACTOR

#include <string>
#include <SFML/Graphics/Sprite.hpp>

#include "rendering/renderable_sprite.h"
#include "scene/icollider.h"

namespace StevensDev
{
namespace sgds
{

class IActor
{
  protected:

    std::string                  d_name;
      //

    sgdr::RenderableSprite      *d_sprite;
      //

    sgds::ICollider             *d_collider;
      //

  public:

    // CONSTRUCTORS

    IActor( std::string name, const sf::Texture &texture );
      // Default constructor

    IActor( const IActor& copy );
      // Copy constructor

    IActor( IActor&& move );
      // Move constructor


    // OPERATORS

    IActor& operator=( const IActor& copy );
      // Copy assignment operator

    IActor& operator=( IActor&& move );
      // Move assignment operator


    // ACCESSORS

    std::string name();
      // Return the actor's name

    sgdr::RenderableSprite* sprite();
      // Return the renderable sprite

    sgds::ICollider* collider();
      // Return the actor's collider


    // MEMBER FUNCTIONS

    void move( float x, float y );
      // Move the actor's sprite
};

} // end sgdr namespace
} // end StevensDev namespace

#endif // Actor
