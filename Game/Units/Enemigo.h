#pragma once
#include "../Unit.h"

/*
	Clase genérica para los enemigos.
*/
class Enemigo : public Unit
{
public:
	Enemigo();
	~Enemigo();
	bool onTick();
};

