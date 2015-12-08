// player_actor_factory.h

#ifndef INCLUDED_PLAYER_ACTOR_FACTORY
# define INCLUDED_PLAYER_ACTOR_FACTORY

#include <string>

#include "controllers/player_controller.h"

namespace StevensDev
{
namespace mgf
{

class PlayerActorFactory
{
  public:

    // MEMBER FUNCTION

    static void create( std::string name );
      // Create a new PlayerActor and PlayerController

    static void destroy( mgc::PlayerController *controller );
      //
};

} // end mgf namespace
} // end StevensDev namespace

#endif // INCLUDED_PLAYER_ACTOR_FACTORY
