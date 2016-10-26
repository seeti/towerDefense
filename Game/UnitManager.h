#pragma once
#include "Unit.h"

class UnitManager
{
private:
	std::vector<Unit*> listadoTorres;
	std::vector<Unit*> listadoEnemigos;

public:
	UnitManager();
	~UnitManager();
	void addTorre(Unit* torre);
	void addenemigo(Unit* enemigo);
	void borraTorre(Unit* torre);
	void borraEnemigo(Unit* enemigo);
};

