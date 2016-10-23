
#include "StaticObject.h"



StaticObject::~StaticObject()
{
}

void StaticObject::setSprite(sf::Sprite sprite)
{
	sfSprite = sprite;
}

void StaticObject::draw(Game* game, const float dt)
{
	game->window.draw(sfSprite);
}

sf::Sprite StaticObject::getSprite()
{
	return sfSprite;
}

sf::FloatRect StaticObject::getLocalBounds() const
{
	return sfSprite.getLocalBounds();
}

sf::FloatRect StaticObject::getGlobalBounds() const
{
	return sfSprite.getGlobalBounds();
}

void StaticObject::setPosition(float x, float y)
{
	sfSprite.setPosition(x, y);
}
