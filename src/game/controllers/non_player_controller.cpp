// non_player_controller.cpp

#include "non_player_controller.h"

namespace StevensDev
{
namespace mgc
{

//
// CONSTRUCTORS
//

NonPlayerController::NonPlayerController( mga::NonPlayerActor *actor )
    : IController( actor )
{
}

NonPlayerController::NonPlayerController( const NonPlayerController& controller )
    : IController( controller.d_actor )
{
}

NonPlayerController::NonPlayerController( NonPlayerController&& controller )
    : IController( controller.d_actor )
{
    controller.d_actor = nullptr;
}


//
// OPERATORS
//

NonPlayerController& NonPlayerController::operator=( const NonPlayerController& copy )
{
    d_actor = copy.d_actor;
}

NonPlayerController& NonPlayerController::operator=( NonPlayerController&& move )
{
    d_actor = move.d_actor;
    move.d_actor = nullptr;
}


//
// MEMBER FUNCTIONS
//

void
NonPlayerController::preTick()
{
}

void
NonPlayerController::tick( float dts )
{
    d_actor->move( 1, 1 );
}

void
NonPlayerController::postTick()
{
}

} // end mgc namespace
} // end StevensDev namespace
