#pragma once
#include "GameState.h"
#include <map>

class GameStatesManager
{
private:
	typedef std::map<std::string, GameState*> estados;
	GameState* estadoActual;

public:

	GameState* getEstadoActual();

	GameStatesManager();
	~GameStatesManager();
};

