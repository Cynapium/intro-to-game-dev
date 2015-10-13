// renderer.h

#ifndef INCLUDED_RENDERER
# define INCLUDED_RENDERER

#include "containers/dynamic_array.h"
#include "containers/map.h"
#include "renderable_sprite.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace StevensDev
{
namespace sgdr
{

class Renderer
{
  private:

    sf::RenderWindow                       *d_window;
      // Represent the renderer window

    sgdc::DynamicArray<RenderableSprite*>   d_sprites;
      // Store all sprites

    sgdc::Map<sf::Texture>                  d_textures;
      // Store all texture loaded


  public:

    // CONSTRUCTORS

    Renderer();
      // Default constructor


    // DESTRUCTOR

    virtual ~Renderer();
      // Destructor


    // MEMBER FUNCTIONS

    void                        draw();
      // Draw all sprites

    void                        addSprite( RenderableSprite *sprite );
      // Add a sprite to the array of sprites

    void                        removeSprite( RenderableSprite *sprite );
      // Remove a sprite from the array

    void                        setupWindow( int width, int height );
      // Setup the window parameters

    bool                        loadTexture( const std::string &name,
                                             const std::string &path );
      //

    const sf::Texture&          getTexture( const std::string& name );
      //

    bool                        isActive();
      // Return false once the window is ready to be destroyed

};

} // End sgdr namespace
} // End StevensDev namespace

#endif // INCLUDED_RENDERER
