#include "UID.h"



unsigned int UID::getNextUID()
{
	return uid++;
}

UID::UID()
{
	uid = 1;
}
UID::UID(unsigned int _uid)
{
	uid = _uid;
}


UID::~UID()
{
}

unsigned int UID::toInt()
{
	return uid;
}
