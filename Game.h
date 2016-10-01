#pragma once

#ifndef GAME_H
#define GAME_H

#include <stack>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "SettingsManager.h"

class GameState;

extern class Game
{
public:

	std::stack<GameState*> states;

	sf::RenderWindow window;
	sf::Sprite background;
	sf::Sprite backgroundBuilding;
	TextureManager texmgr;

	void pushState(GameState* state);
	void popState();
	void changeState(GameState* state);
	GameState* peekState();

	void gameLoop();

	Game();
	~Game();
} gGame;

#endif /* GAME_HPP */