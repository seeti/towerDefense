#include "GameStateStart.h"
#include "GameStateBuilding.h"
#include <iostream>

GameStateStart::GameStateStart(Game* game)
{
	this->game = game;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->view.setSize(pos);
	pos *= 0.5f;
	this->view.setCenter(pos);

	this->cargaFondo();
	this->createMenu();
}

void GameStateStart::draw(const float dt)
{
	this->game->window.setView(this->view);

	this->game->window.clear(sf::Color::Black);
	this->game->window.draw(this->game->background);

	return;
}

void GameStateStart::update(const float dt)
{
}

void GameStateStart::cargaFondo()
{
	this->game->texmgr.loadTexture("background", "media/bg.jpg");
	this->game->background.setTexture(this->game->texmgr.getRef("background"));
}

void GameStateStart::createMenu()
{
	sf::String menu[3] = {"Jugar", "Opciones", "Salir"};
	
	for each (sf::String var in menu)
	{
		std::cout << (std::string)var << std::endl;
	}

	sf::RectangleShape rectBoton;

}

void GameStateStart::handleInput()
{
	sf::Event event;

	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
			/* Close the window */
			case sf::Event::Closed:
			{
				game->window.close();
				break;
			}
			
			case sf::Event::KeyPressed:
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					this->game->window.close();
					break;
				}

				if (event.key.code == sf::Keyboard::L)
				{
					std::cout << "Entrando en modo building" << std::endl;
					this->enterBuildMode();
					break;
				}
			}
			default: break;
		}
	}

	return;
}

void GameStateStart::enterBuildMode()
{
	this->game->pushState(new GameStateBuilding(this->game));

	return;
}

GameStateStart::~GameStateStart()
{
}
