#include "GameStatesManager.h"
#include "GameManager.h"
#include <iostream>

GameStatesManager::GameStatesManager()
{
	this->estadoActual = nullptr;

	estados listaEstados;
	estados::iterator it = listaEstados.find("gameManager");
	if (it != listaEstados.end())
	{
		std::cout << "No existe, lo creamos" << std::endl;
		listaEstados["gameManager"] = new GameManager();
		this->estadoActual = listaEstados["gameManager"];
	}
}

GameState* GameStatesManager::getEstadoActual()
{
	return this->estadoActual;
}

GameStatesManager::~GameStatesManager()
{
}
