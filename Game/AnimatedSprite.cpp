#include "AnimatedSprite.h"
#include "../Game.h"
#include <iostream>


AnimatedSprite::AnimatedSprite(std::string nombre, const char * rutaImagen)
{
	try {
		sfTexture = gGame.pTextureManager->loadFromFile(nombre, rutaImagen);	// Si hay cualquier error con la animaci�n, se borra la Unit y se bloquea todo el c�digo.
	}
	catch (...)
	{
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

void AnimatedSprite::update(const float elapsed)
{
	lastTick += elapsed;	// Actualizaci�n del contador de tick.
	if (lastTick < 0.2f)	// Si la animaci�n lleva menos de 0.2 ticks (segundos) sin actualizarse se detiene el c�digo.
		return;
	//std::cout << "Animando " << frameActual << "("<< frameList[frameActual] <<")"<< std::endl;
	frameActual++;
	if (frameActual >= 4)	// Cada ciclo de animaci�n tiene 4 frames (del 0 al 3), cuando se pasa del cuarto se resetea.
		frameActual = 0;
	lastTick = 0.0f;
}

void AnimatedSprite::setPosition(float x, float y)
{
	sfSprite.setPosition(x, y);
}

void AnimatedSprite::setOrigin(bool centered)			// TODO: Este m�todo no me centra bien el sprite, los dos cout devuelven 0. ** PENDIENTE DE REVISAR **
{
	if (centered) {
		setOrigin(sfSprite.getGlobalBounds().width / 2, sfSprite.getGlobalBounds().height / 2);
	}
	
	//std::cout << "TextureWidth = "<< sfSprite.getGlobalBounds().width / 2 << std::endl;
	//std::cout << "TextureHeight = " << sfSprite.getGlobalBounds().height / 2 << std::endl;
}

void AnimatedSprite::setOrigin(float x, float y)		// Este m�todo (con el drag�n) pasando x=100, y=100 lo centra correctamente.
{
	sfSprite.setOrigin(sf::Vector2f(x, y));
}

void AnimatedSprite::setDireccion(int dir)
{
	this->direccion = dir;
}

void AnimatedSprite::draw() {
	int frame = frameList[frameActual];
	sf::IntRect rectSourceSprite(frame * sizeX,	// Multiplicando el frame actual por el tama�o de cada frame tenemos la posicion del primer pixel del frame a mostrar.
		direccion * sizeY,	// Multiplicando la direcci�n (que tambi�n representa cada fila de frames) actual por el tama�o de cada frame tenemos la posicion del primer pixel del frame a mostrar.
		sizeX,	// tama�o maximo del frame.
		sizeY);
	//sf::Sprite sprite(sfTexture, rectSourceSprite);		// He comentado esta l�nea para utilizar sfSprite, y poder acceder a �l desde el resto de la clase
	sfSprite.setTexture(sfTexture);
	sfSprite.setTextureRect(rectSourceSprite);
	gGame.pGameWindow.draw(sfSprite);
}
