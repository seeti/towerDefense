#include "Torre.h"
#include <iostream>

Torre::Torre()
{
}


Torre::~Torre()
{
}

bool Torre::onTick(const float elapsed)
{
	std::cout << "Torre::onTick" << std::endl;
	return true;
}
