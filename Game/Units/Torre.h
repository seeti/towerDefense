#pragma once
#include "../Unit.h"

/*
	Clase gen�rica para las torres.
*/
class Torre : public Unit
{
public:
	Torre();
	~Torre();

	bool onTick(const float elapsed);
};

