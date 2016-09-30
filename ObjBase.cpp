#include <iostream>
#include "ObjBase.h"
#include "ObjectManager.h"
#include "Game.h"


ObjBase::ObjBase()
{
	uid = gObjManager.generateUID();
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
		sfSprite.setOrigin(sfSprite.getGlobalBounds().width / 2, sfSprite.getGlobalBounds().height / 2);
		return true;
	}
	return false;
}

void ObjBase::onCreate()
{
	gObjManager.add(this);
}

sf::FloatRect ObjBase::getAbsoluteRect()
{
	float fixedX = sfSprite.getGlobalBounds().width / 2;
	float fixedY = sfSprite.getGlobalBounds().height / 2;
	sf::FloatRect rect(
		p.y - fixedY,
		p.x - fixedX,
		p.y + fixedY,
		p.x - fixedX
		);
	return rect;
}

UID ObjBase::getUID()
{
	return uid;
}
