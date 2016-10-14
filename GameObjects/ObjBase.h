#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "Posicion.h"
#include "UID.h"
#include "../GameAnimations/AnimatedSprite.h"
#include "../Game.h"

/*
 * Clase madre para todos los objetos del mundo que pueden/o con los que se puede interactuar. eg: Torres, personajes ...
*/
class ObjBase
{
protected:
	UID uid;
	float fRange;

public:
	Posicion p;
	ObjBase();
	~ObjBase();
	//virtual sf::Sprite getSprite() = 0;
	virtual sf::FloatRect getLocalBounds() const = 0;
	virtual sf::FloatRect getGlobalBounds() const = 0;
	sf::Rect<float> getFixedBounds();
	sf::FloatRect getAbsoluteRect();

	virtual bool onTick(const float dt);
	virtual void draw(Game* game, const float dt = 0.0f ) = 0;
	virtual bool placeAt(int x, int y, bool bIgnoreChecks = false) = 0;

	virtual const char* getObjectName() = 0;
	virtual char* getIconSrc() = 0;
	void onCreate();
	UID getUID();
	float getRange();
	void setRange(float range);
};