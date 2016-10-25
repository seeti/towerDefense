#pragma once
#include "SFML/Graphics.hpp"
#include "Game\Unit.h"

extern class Game
{
private:
	Unit* unidad;
public:
	int screenWidth;
	int screenHeight;
	sf::RenderWindow window;
	void onTick();
	Game();
	~Game();
} gGame;

