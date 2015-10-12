// renderable_sprite.h

#ifndef INCLUDED_RENDERABLE_SPRITE
# define INCLUDED_RENDERABLE_SPRITE

#include <SFML/Graphics/Sprite.hpp>

namespace StevensDev
{
namespace sgdr
{

class RenderableSprite
{
  private:

    sf::Sprite                  d_sprite;
      // The sprite represented by the class


  public:

    // CONSTRUCTOR

    RenderableSprite();
      // Create a sprite at position ( 0, 0 )

    RenderableSprite( float x, float y );
      // Create a RenderableSprite with a given position

    RenderableSprite( const RenderableSprite &copy );
      // Copy constructor

    RenderableSprite( RenderableSprite &&move );
      // Move constructor


    // DESTRUCTOR

    virtual ~RenderableSprite();
      // Destructor


    // OPERATORS

    RenderableSprite&           operator=( const RenderableSprite &copy );
      // Copy operator


    // ACCESSOR

    const sf::Sprite            sprite() const;
      // Return the private sprite


    // MEMBER FUNCTIONS

    float                       getPositionX();
      // Get absolute X position

    float                       getPositionY();
      // Get absolute Y position

    void                        setPosition( float x, float y );
      // Set absolute (x, y) position

    void                        move( float x, float y );
      // Increments the position by the given parameter

};

} // End sgdr namespace
} // End StevensDev namespace

#endif // INCLUDED_RENDERABLE_SPRITE
