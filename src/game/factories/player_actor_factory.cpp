// player_actor_factory.cpp

#include "player_actor_factory.h"

#include "scene/scene.h"
#include "rendering/renderer.h"
#include "actors/player_actor.h"
#include "controllers/player_controller.h"

#include <SFML/Graphics/Sprite.hpp>

namespace StevensDev
{
namespace mgf
{

//
// MEMBER FUNCTION
//

#include<iostream>
void
PlayerActorFactory::create( std::string name )
{
    sgds::Scene             &scene = sgds::Scene::inst();
    sgdr::Renderer          *renderer = scene.renderer();
    const sf::Texture       &texture = renderer->getTexture( name );
    mga::PlayerActor        *actor = new mga::PlayerActor( name, texture );
    mgc::PlayerController   *controller = new mgc::PlayerController( actor );

    renderer->addSprite( actor-> sprite() );
    scene.addTickable( controller );
}

} // end mgf namespace
} // end StevensDev namespace
