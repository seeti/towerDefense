#pragma once
#include "SFML/Graphics.hpp"

class AnimatedSprite
{
private:
	sf::Texture sfTexture;				///< Textura del objeto.
	sf::Sprite sfSprite;				///< Sprite del objeto.
	int sizeX;							///< Tamaño X de cada frame.
	int sizeY;							///< Tamaño Y de cada frame.
	sf::Clock clock;					///< Reloj del juego.
	int frameList[4] = { 0, 1, 2, 1};	///< La animación completa se compone de un ciclo entero de las animaciones: inicio - final - inicio.
	int frameActual = 0;				///< Contador de frames.
	int direccion = 0;					///< Direccion 0-4: 0 = SUR, 1 = OESTE, 2 = ESTE, 3 = NORTE.
public:
	AnimatedSprite(const char * rutaImagen);
	AnimatedSprite();
	~AnimatedSprite();
	void draw();						///< Dibuja el objeto en pantalla.
};

