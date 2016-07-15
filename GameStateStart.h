#pragma once

#ifndef GAMESTATESTART_H
#define GAMESTATESTART_H

#include <SFML/Graphics.hpp>
#include "GameState.h"

class GameStateStart : public GameState
{
private:
	sf::View view;
	void loadGame();

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();
	
	GameStateStart(Game* game);

	//GameStateStart();
	~GameStateStart();
};

#endif /* GAMESTATESTART_H */