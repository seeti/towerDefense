#include <iostream>
#include "ObjBase.h"
#include "ObjectManager.h"
#include "Game.h"
#include <iostream>

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

sf::Rect<float> ObjBase::getFixedBounds()
{
	sf::Rect<float> rect(sfSprite.getGlobalBounds());
	rect.top -= 5;
	rect.left -= 5;
	rect.height += 10;
	rect.width += 10;
	return rect;
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

bool ObjBase::placeAt(int x, int y, bool bIgnoreChecks)
{
	if (p.moveTo(x, y))
	{
		ObjBase* obj = gObjManager.checkCollision(this);
		if (obj && !bIgnoreChecks)
		{
			//No debo moverme. TODO: poner el sprite de color rojo en vez de bloquear su avance?
		}
		else
		{
			p.x = x;
			p.y = y;
		}
		sfSprite.setPosition((float)p.x, (float)p.y);
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
