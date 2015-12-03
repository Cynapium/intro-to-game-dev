// renderable_sprite.cpp

#include "renderable_sprite.h"

namespace StevensDev
{
namespace sgdr
{

//
// CONSTRUCTORS
//

RenderableSprite::RenderableSprite( const sf::Texture &texture )
    : d_sprite( texture )
{
}

RenderableSprite::RenderableSprite( const RenderableSprite &copy )
    : d_sprite( copy.d_sprite )
{
}

RenderableSprite::RenderableSprite( RenderableSprite &&move )
    : d_sprite( std::move( move.d_sprite ) )
{
}


//
// DESTRUCTOR
//

RenderableSprite::~RenderableSprite()
{
}


//
// OPERATOR
//

RenderableSprite&
RenderableSprite::operator=( const RenderableSprite &copy )
{
    d_sprite = copy.d_sprite;

    return *this;
}


//
// ACCESSOR
//

const sf::Sprite
RenderableSprite::sprite() const
{
    return d_sprite;
}


//
// MEMBER FUNCTIONS
//

float
RenderableSprite::getPositionX()
{
    return d_sprite.getPosition().x;
}

float
RenderableSprite::getPositionY()
{
    return d_sprite.getPosition().y;
}

void
RenderableSprite::setPosition( float x, float y )
{
    d_sprite.setPosition( x, y );
}

void
RenderableSprite::move( float x, float y )
{
    d_sprite.move( x, y );
}

const int
RenderableSprite::height() const
{
    return d_sprite.getTextureRect().height;
}

const int
RenderableSprite::width() const
{
    return d_sprite.getTextureRect().width;
}


} // End sgdr namespace
} // End StevensDev namespace
