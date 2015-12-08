// player_controller.h

#ifndef INCLUDED_PLAYER_CONTROLLER
# define INCLUDED_PLAYER_CONTROLLER

#include "scene/icontroller.h"
#include "actors/player_actor.h"
#include "input/input.h"
#include "event/ievent.h"

namespace StevensDev
{
namespace mgc
{

class PlayerController : public sgds::IController
{
  private:

    std::function<void( const sgde::IEvent& )>  d_onRight;
    std::function<void( const sgde::IEvent& )>  d_onLeft;
    std::function<void( const sgde::IEvent& )>  d_onDown;
    std::function<void( const sgde::IEvent& )>  d_onUp;
      //

    sgdi::InputType                             d_last;
      //

  public:

    // CONSTRUCTORS

    PlayerController( mga::PlayerActor *actor );
      // Default constructor

    PlayerController( const PlayerController& copy );
      // Copy constructor

    PlayerController( PlayerController&& move );
      // Move constructor


    // OPERATORS

    PlayerController& operator=( const PlayerController& copy );
      // Copy assignment operator

    PlayerController& operator=( PlayerController&& move );
      // Move assignment operator


    // MEMBER FUNCTIONS

    void reverse();

    virtual void preTick();
      //

    virtual void tick( float dts );
      //

    virtual void postTick();
      //


    // EVENTS

    void onLeft( const sgde::IEvent& event );
    void onRight( const sgde::IEvent& event );
    void onUp( const sgde::IEvent& event );
    void onDown( const sgde::IEvent& event );
};

} // end mgc namespace
} // end StevensDev namespace

#endif // PlayerController
