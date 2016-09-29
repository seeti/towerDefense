#include "ObjectManager.h"
#include "GameState.h"



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
		game->window.draw(obj->getSprite());
	}
}
