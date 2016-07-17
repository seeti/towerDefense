#include <iostream>
#include "GameStateStart.h"
#include "GameStateBuilding.h"

GameStateBuilding::GameStateBuilding(Game* game)
{
	this->game = game;
	this->actionState = ActionState::NONE;

	this->game->texmgr.loadTexture("background-building", "media/background_building.jpg");
	this->game->backgroundBuilding.setTexture(this->game->texmgr.getRef("background-building"));
}

void GameStateBuilding::draw(const float dt)
{
	this->game->window.clear(sf::Color::Black);
	//this->game->window.setView(this->gameView);
	this->game->window.draw(this->game->backgroundBuilding);
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
				case sf::Keyboard::Escape:
					//this->game->window.close();
					this->leaveBuildMode();
					break;

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

void GameStateBuilding::leaveBuildMode()
{
	this->game->pushState(new GameStateStart(this->game));

	return;
}

GameStateBuilding::~GameStateBuilding()
{
}
