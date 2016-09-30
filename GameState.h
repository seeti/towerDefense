#pragma once

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Game.h"
#include "ObjBase.h"
#include <Windows.h>

class GameState
{
public:

	Game* game;
	ObjBase* placingObject;	// objeto que se está creando.
	
	virtual void draw(const float dt) = 0;
	virtual void update(const float dt) = 0;
	virtual void handleInput() = 0;

	GameState();
	~GameState();
};

#endif /* GAMESTATE_H */