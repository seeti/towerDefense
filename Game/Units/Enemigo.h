#pragma once
#include "../Unit.h"

/*
	Clase gen�rica para los enemigos.
*/
class Enemigo : public Unit
{
public:
	Enemigo();
	~Enemigo();
	bool onTick(const float elapsed);
};

