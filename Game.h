#pragma once
#include "SFML/Graphics.hpp"
#include "Game\Unit.h"
#include "Game\UnitManager.h"
#include "Game\Units\Enemigos\Dragon.h"

extern class Game
{
private:
	Dragon * unidad;
public:
	int screenWidth;
	int screenHeight;
	sf::RenderWindow window;
	void onTick();
	Game();
	~Game();
} gGame;

