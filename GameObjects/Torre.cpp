#include "Torre.h"
#include "../GameAnimations/TextureManager.h"
#include "../Game.h"
#include <iostream>

Torre::Torre() : ObjBase()
{
	onLoadTexture();
	std::cout << "Creando torre con uid 0x" << getUID().toInt();
	fRange = 80.f;
}


Torre::~Torre()
{
}

char* Torre::getIconSrc()
{
	return "media/torreta2.png";
}

const char* Torre::getObjectName()
{
	return "torreta";
}

void Torre::onLoadTexture()
{
	gGame.texmgr.loadTexture(getObjectName(), getIconSrc());
	sfTexture = gGame.texmgr.getRef("torreta");
	sf::Sprite sprite(sfTexture);
	setSprite(sprite);
}

bool Torre::onTick(const float dt)
{
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
