// renderer.cpp

#include "renderer.h"

namespace StevensDev
{
namespace sgdr
{

//
// CONSTRUCTORS
//

Renderer::Renderer()
    : d_window()
{
}


//
// DESTRUCTOR
//

Renderer::~Renderer()
{
}


//
// MEMBER FUNCTIONS
//

void
Renderer::draw()
{
    // Clear
    d_window->clear( sf::Color( 255, 255, 255 ) );

    // Draw
    for ( int i = 0; i < d_sprites.length(); i++ )
    {
        d_window->draw( d_sprites[i]->sprite() );
    }

    // Display
    d_window->display();
}

void
Renderer::addSprite( RenderableSprite *sprite )
{
    d_sprites.push( sprite );
}

void
Renderer::removeSprite( RenderableSprite *sprite )
{
    for ( int i = 0; i < d_sprites.length(); i++ )
    {
        if ( d_sprites[i] == sprite )
        {
            d_sprites.removeAt( i );
            break;
        }
    }
}

void
Renderer::setupWindow( int width, int height )
{
    d_window = new sf::RenderWindow( sf::VideoMode( width, height ), "x" );
}

bool
Renderer::loadTexture( const std::string &name, const std::string &path )
{
    sf::Texture         texture;

    if ( !texture.loadFromFile( path ) )
        return false;

    d_textures[name] = texture;

    return true;
}

void
Renderer::setRepeated( const std::string &name, const bool repeat )
{
    d_textures[name].setRepeated( repeat );
}

const sf::Texture&
Renderer::getTexture( const std::string &name )
{
    return d_textures[name];
}

bool
Renderer::isActive()
{
    return d_window->isOpen();
}


} // End sgdr namespace
} // End StevensDev namespace
