#include "GameManager.h"
#include "Game\Units\Enemigos\Dragon.h"



GameManager::GameManager()
{
	listadoEnemigos = new UnitManager();
	listadoTorres = new UnitManager();
	gbcEnemigos = new ColectorBasura();
	gbcTorres = new ColectorBasura();

	listadoEnemigos->push_back(new Dragon());
}


GameManager::~GameManager()
{
	delete listadoEnemigos;
	delete listadoTorres;
	delete gbcEnemigos;
	delete gbcTorres;
}

void GameManager::onTick()
{
	listadoEnemigos->onTick(gbcEnemigos);
	listadoTorres->onTick(gbcTorres);

	gbcEnemigos->onTick(listadoEnemigos);
	gbcTorres->onTick(listadoTorres);
}
