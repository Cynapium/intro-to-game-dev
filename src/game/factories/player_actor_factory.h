// player_actor_factory.h

#ifndef INCLUDED_PLAYER_ACTOR_FACTORY
# define INCLUDED_PLAYER_ACTOR_FACTORY

#include <string>

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
};

} // end mgf namespace
} // end StevensDev namespace

#endif // INCLUDED_PLAYER_ACTOR_FACTORY
