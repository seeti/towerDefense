#include "Torre.h"
#include <iostream>

Torre::Torre()
{
}


Torre::~Torre()
{
}

bool Torre::onTick()
{
	std::cout << "Torre::onTick" << std::endl;
	return true;
}
