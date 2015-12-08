//
// File: scene.cpp
// Author: Barbara Crepeau
//

#include "scene.h"

#include <cassert>

namespace StevensDev
{
namespace sgds
{

Scene *Scene::d_instance = nullptr;

//
// CONSTRUCTOR
//

Scene::Scene()
    : d_renderer( nullptr ), d_scene_graph( nullptr )
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

sgdr::Renderer*
Scene::renderer()
{
    assert( d_renderer != nullptr );

    return d_renderer;
}

NxNSceneGraph*
Scene::graph()
{
    assert( d_scene_graph != nullptr );

    return d_scene_graph;
}


//
// MUTATOR
//

void
Scene::setRenderer( sgdr::Renderer *renderer )
{
    d_renderer = renderer;
}

void
Scene::setGraph( int dimensions, int divisions )
{
    if ( d_scene_graph )
    {
        removeTickable( d_scene_graph );
        delete d_scene_graph;
    }

    d_scene_graph = new NxNSceneGraph( dimensions, divisions );
    addTickable( d_scene_graph );
}

//
// MEMBER FUNCTIONS
//

int
Scene::width()
{
    return d_scene_graph->dimensions();
}

int
Scene::height()
{
    return d_scene_graph->dimensions();
}

void
Scene::tick()
{
    time_t prev = d_time;

    time( &d_time );

    // Pre-tick
    for ( int i = 0; i < d_tickables.length(); i++ )
    {
        d_tickables[i]->preTick();
    }

    // Tick
    for ( int i = 0; i < d_tickables.length(); i++ )
    {
        d_tickables[i]->tick( prev - d_time );
    }

    // Post tick
    for ( int i = 0; i < d_tickables.length(); i++ )
    {
        d_tickables[i]->postTick();
    }
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

