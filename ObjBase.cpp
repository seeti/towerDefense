#include <iostream>
#include "ObjBase.h"
#include "ObjectManager.h"
#include "Game.h"


ObjBase::ObjBase()
{
}


ObjBase::~ObjBase()
{
}

sf::Sprite ObjBase::getSprite()
{
	return sfSprite;
}

void ObjBase::setSprite(sf::Sprite sprite)
{
	sfSprite = sprite;
}

bool ObjBase::onTick()
{
	//std::cout << "Tick" << std::endl;
	//gGame.window.draw(sfSprite);
	return true;
}

bool ObjBase::placeAt(int x, int y)
{
	if (p.moveTo(x, y))
	{
		sfSprite.setPosition((float)x, (float)y);
		return true;
	}
	return false;
}

void ObjBase::onCreate()
{
	gObjManager.add(this);
}