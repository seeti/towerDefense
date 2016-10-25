#pragma once
#include "SFML/Graphics.hpp"

class AnimatedSprite
{
private:
	sf::Texture sfTexture;
	sf::Sprite sfSprite;
	int sizeX;	///< Tamaño X de cada frame.
	int sizeY;	///< Tamaño Y de cada frame.
	sf::Clock clock;
	int frameList[5] = { 0, 1, 2, 1 };	///< La animación completa se compone de un ciclo entero de las animaciones: inicio -> final -> inicio.
	int frameActual = 0;	///< Contador de frames.
	int direccion = 0;	///< Direccion 0-4: 0 = SUR, 1 = OESTE, 2 = ESTE, 3 = NORTE.
public:
	AnimatedSprite(const char * rutaImagen);
	AnimatedSprite();
	~AnimatedSprite();
	void draw();
};

