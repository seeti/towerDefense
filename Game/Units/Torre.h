#pragma once
#include "../Unit.h"

/*
	Clase genérica para las torres.
*/
class Torre : public Unit
{
public:
	Torre();
	~Torre();

	bool onTick();
};

