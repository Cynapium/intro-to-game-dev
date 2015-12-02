// player_controller.cpp

#include "player_controller.h"

#include "input/input.h"

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
PlayerController::preTick()
{
}

void
PlayerController::tick( float dts )
{
    sgdi::Input                 &in = sgdi::Input::inst();

    if ( in.isDown( sgdi::KEY_Right ) )
        d_actor->move( 2, 0 );
    if ( in.isDown( sgdi::KEY_Left ) )
        d_actor->move( -2, 0 );
    if ( in.isDown( sgdi::KEY_Up ) )
        d_actor->move( 0, -2 );
    if ( in.isDown( sgdi::KEY_Down ) )
        d_actor->move( 0, 2 );
}

void
PlayerController::postTick()
{
}


} // end mgc namespace
} // end StevensDev namespace
