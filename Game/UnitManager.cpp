#include "UnitManager.h"



UnitManager::UnitManager()
{
	listadoEnemigos.clear();
	listadoTorres.clear();
}


UnitManager::~UnitManager()
{
	while (listadoEnemigos.size() > 0)
	{
		delete listadoEnemigos.at(0);
	}
	while (listadoTorres.size() > 0)
	{
		delete listadoTorres.at(0);
	}
}

void UnitManager::addTorre(Torre * torre)
{
	listadoTorres.insert(listadoTorres.end(), torre);
}

void UnitManager::addEnemigo(Enemigo * enemigo)
{
	listadoEnemigos.insert(listadoEnemigos.end(), enemigo);
}

void UnitManager::borraTorre(Torre * torre)
{
	for (int i = 0; i < listadoTorres.size(); i++)
	{
		if (listadoTorres.at(i) == torre)
		{
			listadoTorres.erase(listadoTorres.begin() + i);
			return;
		}
	}
}

void UnitManager::borraEnemigo(Enemigo * enemigo)
{
	for (int i = 0; i < listadoEnemigos.size(); i++)
	{
		if (listadoEnemigos.at(i) == enemigo)
		{
			listadoEnemigos.erase(listadoEnemigos.begin() + i);
			return;
		}
	}
}


