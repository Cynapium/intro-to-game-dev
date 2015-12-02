// non_player_actor_factory.h

#ifndef INCLUDED_NON_PLAYER_ACTOR_FACTORY
# define INCLUDED_NON_PLAYER_ACTOR_FACTORY

#include <string>

namespace StevensDev
{
namespace mgf
{

class NonPlayerActorFactory
{
  public:

    // MEMBER FUNCTION

    static void create( std::string name );
      // Create a new NonPlayerActor and NonPlayerController
};

} // end mgf namespace
} // end StevensDev namespace

#endif // INCLUDED_NON_PLAYER_ACTOR_FACTORY
