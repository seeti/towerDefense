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
			/* Resize the window */
			case sf::Event::Resized:
			{
				this->view.setSize(event.size.width, event.size.height);
				this->game->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0)));
				this->game->background.setScale(
				float(event.size.width) / float(this->game->background.getTexture()->getSize().x),
				float(event.size.height) / float(this->game->background.getTexture()->getSize().y));
				break;
			}
			case sf::Event::KeyPressed:
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					std::cout << "Saliendo" << std::endl;
					this->game->window.close();
					break;
				}

				if (event.key.code == sf::Keyboard::L)
				{
					std::cout << "Entrando en modo building" << std::endl;
					//this->game->pushState(new GameStateBuilding(this->game));
					this->loadGame();
					break;
				}
			}
			default: break;
		}
	}

	return;
}

void GameStateStart::loadGame()
{
	this->game->pushState(new GameStateBuilding(this->game));

	return;
}

GameStateStart::~GameStateStart()
{
}
