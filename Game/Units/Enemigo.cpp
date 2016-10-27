#include "Enemigo.h"
#include <iostream>

Enemigo::Enemigo()
{
}


Enemigo::~Enemigo()
{
}

bool Enemigo::onTick(const float elapsed)
{
	draw(elapsed);
	return true;
}
