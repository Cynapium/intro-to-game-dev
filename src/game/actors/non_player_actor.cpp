// non_player_actor.cpp

#include "non_player_actor.h"

namespace StevensDev
{
namespace mga
{

//
// CONSTRUCTORS
//

NonPlayerActor::NonPlayerActor( std::string name, const sf::Texture& texture )
    : IActor( name, texture )
{
}

NonPlayerActor::NonPlayerActor( const NonPlayerActor& copy )
    : IActor( copy )
{
}

NonPlayerActor::NonPlayerActor( NonPlayerActor&& move )
    : IActor( move )
{
}

} // end mga namespace
} // end StevensDev namespace
