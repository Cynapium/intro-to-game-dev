// non_player_controller.h

#ifndef INCLUDED_NON_PLAYER_CONTROLLER
# define INCLUDED_NON_PLAYER_CONTROLLER

#include "scene/icontroller.h"
#include "actors/non_player_actor.h"
#include "event/ievent.h"

#include <functional>

namespace StevensDev
{
namespace mgc
{

class NonPlayerController : public sgds::IController
{
  private:

    //std::function<void( const sgde::IEvent& )>  d_onCollision;
      //


  public:

    // CONSTRUCTORS

    NonPlayerController( mga::NonPlayerActor *actor );
      // Default constructor

    NonPlayerController( const NonPlayerController& copy );
      // Copy constructor

    NonPlayerController( NonPlayerController&& move );
      // Move constructor


    // OPERATORS

    NonPlayerController& operator=( const NonPlayerController& copy );
      // Copy assignment operator

    NonPlayerController& operator=( NonPlayerController&& move );
      // Move assignment operator


    // MEMBER FUNCTIONS

    virtual void preTick();
      //

    virtual void tick( float dts );
      //

    virtual void postTick();
      //


    // EVENT

    void onCollision( const sgde::IEvent& event );
};

} // end mgc namespace
} // end StevensDev namespace

#endif // NonPlayerController
