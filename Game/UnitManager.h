#pragma once
#include "Units/Enemigo.h"
#include "Units/Torre.h"

/*
	Clase que guarda un listado para cada enemigo y para cada torreta existentes.
*/
class UnitManager
{
private:
	std::vector<Torre*> listadoTorres;		///< Listado de Torres.
	std::vector<Enemigo*> listadoEnemigos;	///< Listado de Enemigos.

public:
	UnitManager();
	~UnitManager();
	void addTorre(Torre* torre);			///< Añade un objeto Torre* a la lista.
	void addEnemigo(Enemigo* enemigo);		///< Añade un objeto Enemigo* a la lista.
	void borraTorre(Torre* torre);			///< Borra el objeto Torre* de la lista.
	void borraEnemigo(Enemigo* enemigo);	///< Borra el objeto Enemigo* de la lista.
};

