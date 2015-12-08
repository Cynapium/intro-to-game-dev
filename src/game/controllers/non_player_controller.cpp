// non_player_controller.cpp

#include "non_player_controller.h"

#include "containers/dynamic_array.h"
#include "event/event_bus.h"
#include "event/ievent.h"
#include "factories/non_player_actor_factory.h"
#include "scene/scene.h"

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
    // FIXME : Movement
    d_actor->move( 1, 1 );
}

void
NonPlayerController::postTick()
{
    // Collide
    sgdc::DynamicArray<sgds::ICollider*> colliders;
    colliders = sgds::Scene::inst().graph()->find( d_actor->collider() );

    if ( colliders.length() > 0 )
    {
        sgde::EventBus::dispatcher().dispatch( sgde::EventType::ATTACK );
    }
}


//
// EVENT
//

void
NonPlayerController::onCollision( const sgde::IEvent& event )
{
    // FIXME : Reverse movement
    d_actor->move( -1, -1 );
}

} // end mgc namespace
} // end StevensDev namespace
