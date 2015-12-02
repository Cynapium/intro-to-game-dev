// player_actor.cpp

#include "player_actor.h"

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
}

PlayerActor::PlayerActor( const PlayerActor& copy )
    : IActor( copy )
{
}

PlayerActor::PlayerActor( PlayerActor&& move )
    : IActor( move )
{
}

} // end mga namespace
} // end StevensDev namespace
