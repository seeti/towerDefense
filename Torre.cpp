#include "Torre.h"



Torre::Torre()
{
}


Torre::~Torre()
{
}

bool Torre::onTick()
{
	if (!(ObjBase*)this->onTick())
		return false;
	return true;
}
