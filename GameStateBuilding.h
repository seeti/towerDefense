#pragma once

#include "GameState.h"

enum class ActionState {NONE, HUMAN, FIRE, WATER};

class GameStateBuilding : public GameState
{
private:
	ActionState actionState;

	sf::View gameView;
	sf::View guiView;

	void leaveBuildMode();

public:

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStateBuilding(Game* game);
	~GameStateBuilding();
};

