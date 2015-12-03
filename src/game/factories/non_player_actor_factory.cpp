// non_player_actor_factory.cpp

#include "non_player_actor_factory.h"

#include "scene/scene.h"
#include "rendering/renderer.h"
#include "actors/non_player_actor.h"
#include "controllers/non_player_controller.h"

#include <SFML/Graphics/Sprite.hpp>

namespace StevensDev
{
namespace mgf
{

void
NonPlayerActorFactory::create( std::string name )
{
    sgds::Scene              &scene = sgds::Scene::inst();
    sgdr::Renderer           *renderer = scene.renderer();
    const sf::Texture        &texture = renderer->getTexture( name );
    mga::NonPlayerActor      *actor = new mga::NonPlayerActor( name, texture );
    mgc::NonPlayerController *controller = new mgc::NonPlayerController( actor );

    renderer->addSprite( actor-> sprite() );
    scene.addTickable( controller );

    scene.graph()->addCollider( actor->collider() );
}

} // end mgf namespace
} // end StevensDev namespace
