// scene.cpp

#include "scene.h"

namespace StevensDev
{
namespace sgds
{

Scene *Scene::d_instance = nullptr;


//
// CONSTRUCTOR
//

Scene::Scene()
    : d_renderer( nullptr )
{
    time( &d_time );
}


//
// ACCESSORS
//

Scene&
Scene::inst()
{
    if ( !d_instance )
    {
        d_instance = new Scene;
    }

    return *d_instance;
}


//
// MUTATOR
//

void
Scene::setRenderer( sgdr::Renderer *renderer )
{
    d_renderer = renderer;
}


//
// MEMBER FUNCTIONS
//

void
Scene::tick()
{
    time_t              prev = d_time;

    time( &d_time );

    // Pre-tick
    for ( int i = 0; i < d_tickables.length(); i++ )
        d_tickables[i]->preTick();

    // Tick
    for ( int i = 0; i < d_tickables.length(); i++ )
        d_tickables[i]->tick( prev - d_time );

    // Post tick
    for ( int i = 0; i < d_tickables.length(); i++ )
        d_tickables[i]->postTick();
}

void
Scene::addTickable( ITickable *tickable )
{
    d_tickables.push( tickable );
}

void
Scene::removeTickable( ITickable *tickable )
{
    for ( int i = 0; i < d_tickables.length(); i++ )
    {
        if ( d_tickables[i] == tickable )
        {
            d_tickables.removeAt( i );
            break;
        }
    }
}

} // End sgds namespace
} // End StevensDev namespace
