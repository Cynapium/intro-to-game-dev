// player_actor.cpp

#include "player_actor.h"

#include "scene/icollider.h"

namespace StevensDev
{
namespace mga
{

//
// CONSTRUCTORS
//

PlayerActor::PlayerActor( std::string name, const sf::Texture& texture )
    : IActor( name, texture )
{
    setPosition( 200, 200 );
}

PlayerActor::PlayerActor( const PlayerActor& actor )
    : IActor( actor )
{
}

PlayerActor::PlayerActor( PlayerActor&& actor )
    : IActor( actor )
{
}

} // end mga namespace
} // end StevensDev namespace
