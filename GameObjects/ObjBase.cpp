#include <iostream>
#include "ObjBase.h"
#include "ObjectManager.h"
#include "../Game.h"
#include <iostream>

ObjBase::ObjBase()
{
	uid = gObjManager.generateUID();
}


ObjBase::~ObjBase()
{
	fRange = 0.f;
}

sf::Rect<float> ObjBase::getFixedBounds()
{
	sf::Rect<float> rect(getGlobalBounds());
	rect.top -= 5;
	rect.left -= 5;
	rect.height += 10;
	rect.width += 10;
	return rect;
}

sf::FloatRect ObjBase::getAbsoluteRect()
{
	sf::Sprite sprite = getSprite();
	float fixedX = sprite.getGlobalBounds().width / 2;
	float fixedY = sprite.getGlobalBounds().height / 2;
	sf::FloatRect rect(
		p.y - fixedY,
		p.x - fixedX,
		p.y + fixedY,
		p.x - fixedX
	);
	return rect;
}

bool ObjBase::onTick(const float dt)
{
	//std::cout << "Tick" << std::endl;
	//gGame.window.draw(sfSprite);
	return true;
}

bool ObjBase::placeAt(int x, int y, bool bIgnoreChecks)
{
	return false;
}

void ObjBase::onCreate()
{
	gObjManager.add(this);
}

UID ObjBase::getUID()
{
	return uid;
}

float ObjBase::getRange()
{
	return fRange;
}

void ObjBase::setRange(float range)
{
	fRange = range;
}
