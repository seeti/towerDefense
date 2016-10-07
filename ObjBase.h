#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "Posicion.h"
#include "UID.h"

/*
 * Clase madre para todos los objetos del mundo que pueden/o con los que se puede interactuar. eg: Torres, personajes ...
*/
class ObjBase
{
protected:
	sf::Sprite sfSprite;
	UID uid;
	float fRange;

	void setSprite(sf::Sprite);
public:
	Posicion p;
	ObjBase();
	~ObjBase();
	sf::Sprite getSprite();
	sf::Rect<float> getFixedBounds();
	virtual bool onTick(const float dt);
	virtual bool placeAt(int x, int y, bool bIgnoreChecks = false);
	virtual const char* getObjectName() = 0;
	virtual char* getIconSrc() = 0;
	void onCreate();
	sf::FloatRect getAbsoluteRect();
	UID getUID();
	float getRange();
	void setRange(float range);
};