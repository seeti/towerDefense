#include "Posicion.h"



Posicion::Posicion()
{
	x = 0;
	y = 0;
}


Posicion::~Posicion()
{
}

//TODO: Checks de posicionamiento
bool Posicion::moveTo(int _x, int _y)
{
	x = _x;
	y = _y;
	return true;
}