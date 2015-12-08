// player_controller.cpp

#include "player_controller.h"

#include "containers/dynamic_array.h"
#include "scene/scene.h"
#include "scene/icollider.h"
#include "event/event_bus.h"
#include "factories/player_actor_factory.h"

namespace StevensDev
{
namespace mgc
{

using std::placeholders::_1;

//
// CONSTRUCTORS
//

PlayerController::PlayerController( mga::PlayerActor *actor )
    : IController( actor ),
      d_onRight( std::bind( &mgc::PlayerController::onRight, this, _1 ) ),
      d_onLeft( std::bind( &mgc::PlayerController::onLeft, this, _1 ) ),
      d_onDown( std::bind( &mgc::PlayerController::onDown, this, _1 ) ),
      d_onUp( std::bind( &mgc::PlayerController::onUp, this, _1 ) ),
      d_onAttacked( std::bind( &mgc::PlayerController::onAttacked, this, _1 ) )
{
    sgde::EventDispatcher &dispatcher = sgde::EventBus::dispatcher();

    dispatcher.add( sgde::EventType::INPUT_KEY_Right, &d_onRight );
    dispatcher.add( sgde::EventType::INPUT_KEY_Left, &d_onLeft );
    dispatcher.add( sgde::EventType::INPUT_KEY_Down, &d_onDown );
    dispatcher.add( sgde::EventType::INPUT_KEY_Up, &d_onUp );
    dispatcher.add( sgde::EventType::ATTACK, &d_onAttacked );
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
    /*
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
    }*/
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
        //std::cout << "COLLIDE " << colliders.length()  << std::endl;
        //reverse();
    }
}

void
PlayerController::onLeft( const sgde::IEvent& event )
{
    d_actor->move( -2, 0 );
}

void
PlayerController::onRight( const sgde::IEvent& event )
{
    d_actor->move( 2, 0 );
}

void
PlayerController::onUp( const sgde::IEvent& event )
{
    d_actor->move( 0, -2 );
}

void
PlayerController::onDown( const sgde::IEvent& event )
{
    d_actor->move( 0, 2 );
}

void
PlayerController::onAttacked( const sgde::IEvent& event )
{
    mgf::PlayerActorFactory::destroy( this );    
}


} // end mgc namespace
} // end StevensDev namespace
