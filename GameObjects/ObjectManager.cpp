#include "ObjectManager.h"
#include "../GameStates/GameState.h"
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

void ObjectManager::onTick(const float dt)
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
		if (!obj->onTick(dt))
		{
			mList.erase(mList.begin() + i);
			continue;
		}
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
		if (obj->getFixedBounds().contains((float)pos.x, (float)pos.y))
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

void ObjectManager::draw(Game * game, const float dt)
{
	if (mList.size() < 1)
		return;
	for (size_t i = 0; i < mList.size(); i++)
	{
		ObjBase* obj = mList.at(i);
		if (!obj)		//Should not happen, since onTick already manages it.
			continue;	//Just keep going and forget it.
		obj->draw(game, dt);
	}
}
