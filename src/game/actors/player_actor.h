// player_actor.h

#ifndef INCLUDED_PLAYER_ACTOR
# define INCLUDED_PLAYER_ACTOR

#include <SFML/Graphics/Sprite.hpp>

#include "scene/iactor.h"


namespace StevensDev
{
namespace mga
{

class PlayerActor : public sgds::IActor
{
  private:

  public:

    // CONSTRUCTORS

    PlayerActor( std::string name, const sf::Texture& texture );
      // Default constructor

    PlayerActor( const PlayerActor& actor );
      // Copy constructor

    PlayerActor( PlayerActor&& actor );
      // Move constructor


    // OPERATORS

    PlayerActor& operator=( const PlayerActor& actor );
      // Copy assignment operator

    PlayerActor& operator=( PlayerActor&& actor );
      // Move assignment operator
};

} // end mga namespace
} // end StevensDev namespace

#endif // PlayerActor
