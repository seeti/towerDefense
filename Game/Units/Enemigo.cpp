#include "Enemigo.h"
#include <iostream>

Enemigo::Enemigo()
{
}


Enemigo::~Enemigo()
{
}

bool Enemigo::onTick()
{
	draw();
	return true;
}
