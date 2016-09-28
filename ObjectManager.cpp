#include "ObjectManager.h"



ObjectManager::ObjectManager()
{
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

void ObjectManager::onTick()
{
	if (mList.size() <= 0)
		return;
	for (size_t i = mList.size(); i > 0; i--)
	{
		if (!mList.at(i)->onTick())
			mList.erase(mList.end() - i);
	}
}
