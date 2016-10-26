#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Game.h"
#include <iostream>


void Game::onTick()
{
	unidad->draw();
}

Game::Game()
{
	std::cout << "Inicializando Game" << std::endl;
	screenWidth = 1280;
	screenHeight = 720;
	window.create(sf::VideoMode(this->screenWidth, this->screenHeight), "Tower Defense");
	window.setFramerateLimit(60);
	window.clear();
	unidad = new Dragon();
}


Game::~Game()
{
}
