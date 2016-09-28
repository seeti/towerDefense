#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

/*
 * Clase madre para todos los objetos del mundo que pueden/o con los que se puede interactuar. eg: Torres, personajes ...
*/
class ObjBase
{
private:
	sf::Texture mTexture;
public:
	ObjBase();
	~ObjBase();
	sf::Texture getTexture();
	virtual bool onTick();
	void onCreate();
};