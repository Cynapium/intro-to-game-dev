// player_controller.cpp

#include "player_controller.h"

#include "containers/dynamic_array.h"
#include "scene/scene.h"
#include "scene/icollider.h"

namespace StevensDev
{
namespace mgc
{

//
// CONSTRUCTORS
//

PlayerController::PlayerController( mga::PlayerActor *actor )
    : IController( actor )
{
}

PlayerController::PlayerController( const PlayerController& controller )
    : IController( controller.d_actor )
{
}

PlayerController::PlayerController( PlayerController&& controller )
    : IController( controller.d_actor )
{
    controller.d_actor = nullptr;
}


//
// OPERATORS
//

PlayerController& PlayerController::operator=( const PlayerController& copy )
{
    d_actor = copy.d_actor;
}

PlayerController& PlayerController::operator=( PlayerController&& move )
{
    d_actor = move.d_actor;
    move.d_actor = nullptr;
}


//
// MEMBER FUNCTIONS
//

void
PlayerController::reverse()
{
    // Move
    if ( d_last == sgdi::KEY_Right )
    {
        d_actor->move( -2, 0 );
    }
    if ( d_last == sgdi::KEY_Left )
    {
        d_actor->move( 2, 0 );
    }
    if ( d_last == sgdi::KEY_Up )
    {
        d_actor->move( 0, 2 );
    }
    if ( d_last == sgdi::KEY_Down )
    {
        d_actor->move( 0, -2 );
    }
}

void
PlayerController::preTick()
{
}

void
PlayerController::tick( float dts )
{
    sgdi::Input &in = sgdi::Input::inst();

    // Move
    if ( in.isDown( sgdi::KEY_Right ) )
    {
        d_actor->move( 2, 0 );
        d_last = sgdi::KEY_Right;
    }
    if ( in.isDown( sgdi::KEY_Left ) )
    {
        d_actor->move( -2, 0 );
        d_last = sgdi::KEY_Left;
    }
    if ( in.isDown( sgdi::KEY_Up ) )
    {
        d_actor->move( 0, -2 );
        d_last = sgdi::KEY_Up;
    }
    if ( in.isDown( sgdi::KEY_Down ) )
    {
        d_actor->move( 0, 2 );
        d_last = sgdi::KEY_Down;
    }
}

#include <iostream>

void
PlayerController::postTick()
{
    // Collide
    sgdc::DynamicArray<sgds::ICollider*> colliders;
    colliders = sgds::Scene::inst().graph()->find( d_actor->collider() );

    if ( colliders.length() > 0 )
    {
        std::cout << "COLLIDE " << colliders.length()  << std::endl;
        //reverse();
    }
}


} // end mgc namespace
} // end StevensDev namespace
