#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Game.h"
#include "GameState.h"
#include "ObjectManager.h"

//Añadido por seeti para hacer unas pruebas
#include "SettingsManager.h"

void Game::pushState(GameState* state)
{
	this->states.push(state);

	return;
}

void Game::popState()
{
	delete this->states.top();
	this->states.pop();

	return;
}

void Game::changeState(GameState* state)
{
	if (!this->states.empty())
		popState();
	pushState(state);

	return;
}

GameState* Game::peekState()
{
	if (this->states.empty()) return nullptr;
	return this->states.top();
}

void Game::gameLoop()
{
	sf::Clock clock;

	// PRUEBAS SEETI

	SettingsManager stMng("config.cfg");

	int prueba = stMng.getIntValueOfKey("ScreenWidth");
	std::cout << "Screen Width: " << prueba << std::endl;

	//if (stMng.keyExists("ScreenWidth"))
	//	std::cout << "existe." << std::endl;

	// FIN PRUEBAS SEETI

	while (this->window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		if (peekState() == nullptr) continue;
		peekState()->handleInput();
		peekState()->update(dt);
		this->window.clear(sf::Color::Black);
		peekState()->draw(dt);
		this->window.display();
	}
}

Game::Game()
{
	this->window.create(sf::VideoMode(1280, 720), "Tower Defense");
	this->window.setFramerateLimit(60);
}

Game::~Game()
{
	while (!this->states.empty()) popState();
}