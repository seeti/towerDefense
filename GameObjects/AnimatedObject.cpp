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
	game->window.draw(animatedSprite);
}

bool AnimatedObject::onTick(const float dt)
{
	sf::Time frameTime = frameClock.restart();
	// Esto creo que es para que se vaya cambiando el frame de la animacion
	animatedSprite.update(frameTime);
	return true;
}

Animation AnimatedObject::getAnimation()
{
	return animacionObjeto;
}
