#include "ObjectManager.h"
#include "GameState.h"
#include <iostream>

ObjectManager::ObjectManager()
{
	mList.empty();
	mList.clear();
}

ObjectManager::~ObjectManager()
{
}

void ObjectManager::add(ObjBase* obj)
{
	if (!obj)
		return;
	mList.insert(mList.end(), obj);
}

void ObjectManager::remove(ObjBase* obj)
{
	if (!obj)
		return;
	for (size_t i = mList.size(); i > 0; i--)
	{
		ObjBase *obAt = mList.at(i);
		if (obAt == NULL)
			return;
		if (obAt == obj)
			mList.erase(mList.end() - i);
	}
}

void ObjectManager::onTick(Game* game)
{
	if (mList.size() < 1)
		return;
	for (size_t i = 0; i < mList.size(); i++)
	{
		ObjBase* obj = mList.at(i);
		if (!obj)
		{
			mList.erase(mList.begin() + i);
			continue;
		}
		if (!obj->onTick())
		{
			mList.erase(mList.begin() + i);
			continue;
		}
		/*std::cout << "Torre en " << obj->getSprite().getGlobalBounds().left <<" - "<< obj->getSprite().getGlobalBounds().width
			<< " / " << obj->getSprite().getGlobalBounds().top << " - " << obj->getSprite().getGlobalBounds().height;*/
		game->window.draw(obj->getSprite());
	}
}

ObjBase* ObjectManager::findObjectAt(sf::Vector2i pos)
{
	if (mList.size() < 1)
		return nullptr;
	for (size_t i = 0; i < mList.size(); i++)
	{
		ObjBase* obj = mList.at(i);
		if (!obj)
			continue;
		if (obj->getFixedBounds().contains(pos.x, pos.y))
			return obj;
		//if (obj->getAbsoluteRect().contains(pos.x, pos.y))
		//	return obj;
	}
	return nullptr;
}

ObjBase * ObjectManager::checkCollision(ObjBase * objNuevo)
{
	if (mList.size() < 1)
		return nullptr;
	if (!objNuevo)
		return nullptr;
	for (size_t i = 0; i < mList.size(); i++)
	{
		ObjBase* obj = mList.at(i);
		if (!obj)
			continue;
		if (obj == objNuevo)
			continue;
		if (obj->getSprite().getGlobalBounds().intersects(objNuevo->getSprite().getGlobalBounds()))
			return obj;
		//if (obj->getAbsoluteRect().contains(pos.x, pos.y))
		//	return obj;
	}
	return nullptr;
}

UID ObjectManager::generateUID()
{
	return getNextUID();
}
