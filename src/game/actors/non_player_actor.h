// non_player_actor.h

#ifndef INCLUDED_NON_PLAYER_ACTOR
# define INCLUDED_NON_PLAYER_ACTOR

#include <SFML/Graphics/Sprite.hpp>

#include "scene/iactor.h"

namespace StevensDev
{
namespace mga
{

class NonPlayerActor : public sgds::IActor
{
  private:


  public:

    // CONSTRUCTORS

    NonPlayerActor( std::string name, const sf::Texture& texture );
      // Default constructor

    NonPlayerActor( const NonPlayerActor& copy );
      // Copy constructor

    NonPlayerActor( NonPlayerActor&& move );
      // Move constructor


    // OPERATORS

    NonPlayerActor& operator=( const NonPlayerActor& copy );
      // Copy assignment operator

    NonPlayerActor& operator=( NonPlayerActor&& move );
      // Move assignment operator
};

} // end mga namespace
} // end StevensDev namespace

#endif // NonPlayerActor
