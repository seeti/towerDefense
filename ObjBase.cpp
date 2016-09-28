#include "ObjBase.h"
#include "ObjectManager.h"


ObjBase::ObjBase()
{
}


ObjBase::~ObjBase()
{
}

sf::Texture ObjBase::getTexture()
{
	return mTexture;
}

bool ObjBase::onTick()
{
	return true;
}

void ObjBase::onCreate()
{
	gObjManager.add(this);
}