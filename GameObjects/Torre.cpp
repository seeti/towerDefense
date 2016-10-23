#include "Torre.h"
#include "ObjectManager.h"
#include "../GameAnimations/TextureManager.h"
#include "../Game.h"
#include <iostream>

Torre::Torre() : AnimatedObject()
{
	onLoadTexture();
	std::cout << "Creando torre con uid 0x" << getUID().toInt();
	fRange = 80.f;
	// Aqui asignamos el spriteSheet a la animación, para posteriormente indicarle cuales son los frames que vamos a utilizar
	animacionObjeto.setSpriteSheet(gGame.texmgr.getRef("prueba-anim"));

	// Aqui vamos recorriendo el spriteSheet (en este caso son 5 frames) y vamos diciendole en rectangulos la posicion y tamaño de cada uno de los frames
	for (int i = 0; i < 5; i++)
		animacionObjeto.addFrame(sf::IntRect(i * 69, 0, 69, 69));

	// Aqui indicamos el tiempo que tiene que durar la animacion, si queremos que la animacion esté pausada (quieta) y si queremos que haga loop constanemente (Cuando acabe, que se inicie de nuevo).
	animatedSprite = AnimatedSprite(sf::seconds(0.4f), true, true);
	animatedSprite.setAnimation(animacionObjeto);	// Asignamos al animatedSprite el conjunto de animaciones que ha de usar.
}


Torre::~Torre()
{
}

char* Torre::getIconSrc()
{
	return "media/prueba.png";
}

bool Torre::placeAt(int x, int y, bool bIgnoreChecks)
{
	if (p.moveTo(x, y))
	{
		ObjBase* obj = gObjManager.checkCollision(this);
		if (obj && !bIgnoreChecks)
		{
			//No debo moverme. TODO: poner el sprite de color rojo en vez de bloquear su avance?
			setColor(sf::Color::Red);
		}
		else
		{
			p.x = x;
			p.y = y;
			setColor(sf::Color::White);
		}
		setPosition((float)p.x, (float)p.y);
		setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
		return true;
	}
	return false;
}

const char* Torre::getObjectName()
{
	return "prueba-anim";
}

void Torre::onLoadTexture()
{
	gGame.texmgr.loadTexture(getObjectName(), getIconSrc());
	//AnimatedObject::setSpriteSheet(gGame.texmgr.getRef("prueba-anim"));
	//animationSprite.addFrame(sf::IntRect(69, 0, 69, 69));

	//animatedSprite:(sf::seconds(0.2), true, false);	 // ????
}

bool Torre::onTick(const float dt)
{
	play();
	elapsedPrimaryAttack += dt;
	if (elapsedPrimaryAttack > primaryAttack)
	{
		std::cout << "Torre 0x" << getUID().toInt() << " ataca\n";
		elapsedPrimaryAttack = 0.0f;
		// TODO: Lanzar proyectiles desde aquí
		// TODO2: crear un manager que controle todos los proyectiles, tanto sus trayectorias como destinos como el moverlos constantemente y hacer que impacten y hagan daño al acercarse al objetivo
	}
	return true;
}

bool Torre::moveTo(int x, int y)
{
	return (bool)static_cast<ObjBase*>(this)->p.moveTo(x, y);
}
