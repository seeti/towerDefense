#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Game.h"


Game::Game()
{
	screenWidth = 1280;
	screenHeight = 720;
	window.create(sf::VideoMode(this->screenWidth, this->screenHeight), "Tower Defense");
	window.setFramerateLimit(60);
}


Game::~Game()
{
}
