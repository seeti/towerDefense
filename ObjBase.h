#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
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

	void setSprite(sf::Sprite);
public:
	Posicion p;
	ObjBase();
	~ObjBase();
	sf::Sprite getSprite();
	virtual bool onTick();
	virtual bool placeAt(int x, int y);
	void onCreate();
	sf::FloatRect getAbsoluteRect();
	UID getUID();
};