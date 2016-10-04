#include "Torre.h"
#include "TextureManager.h"
#include "Game.h"
#include <iostream>

Torre::Torre() : ObjBase()
{
	onLoadTexture();
	std::cout << "Creando torre con uid 0x" << getUID().toInt();
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

bool Torre::onTick()
{
	/*if (!(ObjBase*)this->onTick())
		return false;*/
	return true;
}

bool Torre::moveTo(int x, int y)
{
	return (bool)static_cast<ObjBase*>(this)->p.moveTo(x, y);
}
