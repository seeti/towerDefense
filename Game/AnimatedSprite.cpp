#include "AnimatedSprite.h"
#include "../Game.h"
#include <iostream>


AnimatedSprite::AnimatedSprite(const char * rutaImagen)
{
	if (!sfTexture.loadFromFile(rutaImagen)) {	// Si hay cualquier error con la animación, se borra la Unit y se bloquea todo el código.
		std::cout << "Error cargando fichero '" << rutaImagen << "'" << std::endl;
		delete this;
		return;
	}
	sizeX = sfTexture.getSize().x / 3;
	sizeY = sfTexture.getSize().y / 4;
}

AnimatedSprite::AnimatedSprite()
{
}

AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::draw() {

	int frame = frameList[frameActual];
	sf::IntRect rectSourceSprite(frame * sizeX,	// Multiplicando el frame actual por el tamaño de cada frame tenemos la posicion del primer pixel del frame a mostrar.
		direccion * sizeY,	// Multiplicando la dirección (que también representa cada fila de frames) actual por el tamaño de cada frame tenemos la posicion del primer pixel del frame a mostrar.
		sizeX,	// tamaño maximo del frame.
		sizeY);
	sf::Sprite sprite(sfTexture, rectSourceSprite);
	sprite.setTextureRect(rectSourceSprite);
	gGame.window.draw(sprite);

	if (clock.getElapsedTime().asSeconds() < 0.2f)
		return;
	std::cout << "Animando " << frameActual << "("<< frameList[frameActual] <<")"<< std::endl;
	frameActual++;
	if (frameActual >= 4)	// Cada ciclo de animación tiene 4 frames (del 0 al 3), cuando se pasa del cuarto se resetea.
		frameActual = 0;
	clock.restart();
}
