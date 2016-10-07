#include "AnimatedObject.h"

sf::FloatRect AnimatedObject::getLocalBounds() const
{
	return sfSprite.getLocalBounds();
}

sf::FloatRect AnimatedObject::getGlobalBounds() const
{
	return sfSprite.getGlobalBounds();
}

void AnimatedObject::draw(Game* game, const float dt)
{
	game->window.draw(sfSprite);
}
