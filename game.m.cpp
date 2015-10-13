// game.m.cpp

#include <iostream>

#include "scene/scene.h"
#include "input/input.h"

#define WIDTH               800
#define HEIGHT              500

int main( int argc, char **argv )
{
    using namespace StevensDev;

    // Setup Renderer
    sgdr::Renderer   *renderer = new sgdr::Renderer();
    renderer->loadTexture( "pika", "resources/textures/test.png" );
    renderer->setupWindow( WIDTH, HEIGHT );

    // Setup Scene
    sgds::Scene                 scene = sgds::Scene::inst();
    scene.setRenderer( renderer );

    // Create sprites
    sgdr::RenderableSprite     *sprite = new sgdr::RenderableSprite( renderer->getTexture( "pika" ) );
    sprite->setPosition( WIDTH / 2 - 25, HEIGHT / 2 - 25 );
    renderer->addSprite( sprite );

    sgdi::Input                 &in = sgdi::Input::inst();

    while ( renderer->isActive() )
    {
        // Display window
        renderer->draw();

        in.preTick();

        if ( in.isDown( sgdi::KEY_Escape ) )
        {
            std::cout << "ESCAPE" << std::endl;
            return 0;
        }

        if ( in.isDown( sgdi::KEY_Right ) )
            sprite->move( 2, 0 );
        if ( in.isDown( sgdi::KEY_Left ) )
            sprite->move( -2, 0 );
        if ( in.isDown( sgdi::KEY_Up ) )
            sprite->move( 0, -2 );
        if ( in.isDown( sgdi::KEY_Down ) )
            sprite->move( 0, 2 );
    }

    return 0;
}
