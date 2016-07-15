#include <iostream>
#include "GameStateBuilding.h"

GameStateBuilding::GameStateBuilding(Game* game)
{
	this->game = game;
	this->actionState = ActionState::NONE;
}

void GameStateBuilding::draw(const float dt)
{
	this->game->window.clear(sf::Color::Black);
	//this->game->window.setView(this->gameView);
	this->game->window.draw(this->game->background);
}

void GameStateBuilding::update(const float dt)
{

}

void GameStateBuilding::handleInput()
{
	sf::Event event;

	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
				case sf::Keyboard::Y:
					std::cout << "ActionState = NONE" << std::endl;
					this->actionState = ActionState::NONE;
					break;

				case sf::Keyboard::U:
					std::cout << "ActionState = HUMAN" << std::endl;
					this->actionState = ActionState::HUMAN;
					break;

				case sf::Keyboard::I:
					std::cout << "ActionState = FIRE" << std::endl;
					this->actionState = ActionState::FIRE;
					break;

				case sf::Keyboard::O:
					std::cout << "ActionState = WATER" << std::endl;
					this->actionState = ActionState::WATER;
					break;
			}
		}
	}
}

GameStateBuilding::~GameStateBuilding()
{
}
