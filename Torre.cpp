#include "Torre.h"
#include "TextureManager.h"
#include "Game.h"

Torre::Torre() : ObjBase()
{
	onLoadTexture();
}


Torre::~Torre()
{
}

void Torre::onLoadTexture()
{
	gGame.texmgr.loadTexture("torreta", "media/torreta.png");
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
	return (bool)(ObjBase*)this->p.moveTo(x, y);
}
