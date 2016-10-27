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

void AnimatedSprite::setPosition(float x, float y)
{
	sfSprite.setPosition(x, y);
}

void AnimatedSprite::setOrigin(bool centered)			// TODO: Este método no me centra bien el sprite, los dos cout devuelven 0. ** PENDIENTE DE REVISAR **
{
	if (centered) sfSprite.setOrigin(sfSprite.getTextureRect().width / 2, sfSprite.getTextureRect().height / 2);
	
	std::cout << sfSprite.getTextureRect().width / 2 << std::endl;
	std::cout << sfSprite.getTextureRect().height / 2 << std::endl;
}

void AnimatedSprite::setOrigin(float x, float y)		// Este método (con el dragón) pasando x=100, y=100 lo centra correctamente.
{
	sfSprite.setOrigin(sf::Vector2f(x, y));
}

void AnimatedSprite::draw(const float elapsed) {

	int frame = frameList[frameActual];
	sf::IntRect rectSourceSprite(frame * sizeX,	// Multiplicando el frame actual por el tamaño de cada frame tenemos la posicion del primer pixel del frame a mostrar.
		direccion * sizeY,	// Multiplicando la dirección (que también representa cada fila de frames) actual por el tamaño de cada frame tenemos la posicion del primer pixel del frame a mostrar.
		sizeX,	// tamaño maximo del frame.
		sizeY);
	//sf::Sprite sprite(sfTexture, rectSourceSprite);		// He comentado esta línea para utilizar sfSprite, y poder acceder a él desde el resto de la clase
	sfSprite.setTexture(sfTexture);
	sfSprite.setTextureRect(rectSourceSprite);
	gGame.window.draw(sfSprite);

	lastTick += elapsed;	// Actualización del contador de tick.
	if (lastTick < 0.2f)	// Si la animación lleva menos de 0.2 ticks (segundos) sin actualizarse se detiene el código.
		return;
	std::cout << "Animando " << frameActual << "("<< frameList[frameActual] <<")"<< std::endl;
	frameActual++;
	if (frameActual >= 4)	// Cada ciclo de animación tiene 4 frames (del 0 al 3), cuando se pasa del cuarto se resetea.
		frameActual = 0;
	lastTick = 0.0f;
}
