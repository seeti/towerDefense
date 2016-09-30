#include <iostream>
#include "GameStateStart.h"
#include "GameStateBuilding.h"
#include "Game.h"
#include "ObjectManager.h"
#include "Torre.h"
#include "MouseCursor.h"

GameStateBuilding::GameStateBuilding(Game* game)
{
	this->game = game;
	this->actionState = ActionState::NONE;

	this->game->texmgr.loadTexture("background-building", "media/background_building.jpg");
	this->game->backgroundBuilding.setTexture(this->game->texmgr.getRef("background-building"));
	objMouseOver = NULL;
}

void GameStateBuilding::draw(const float dt)
{
	this->game->window.clear(sf::Color::Black);
	//this->game->window.setView(this->gameView);
	this->game->window.draw(this->game->backgroundBuilding);
	gObjManager.onTick(game);
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

					case sf::Keyboard::H:
						std::cout << "ActionState = CREAR TORRE" << std::endl;
						this->actionState = ActionState::BUILDING;
						break;
				}
				break;
			case sf::Event::MouseButtonPressed:
			{
				switch (event.mouseButton.button)
				{
					case sf::Mouse::Left:
						std::cout << "Action = Pulsa boton Izquierdo" << std::endl;
						if (this->actionState == ActionState::BUILDING)
						{
							std::cout << "Action = Emplaza torre en " << sf::Mouse::getPosition().x << "/" << sf::Mouse::getPosition().y << std::endl;
							this->actionState = ActionState::NONE;
							Torre* torre = new Torre();
							torre->placeAt(sf::Mouse::getPosition(this->game->window).x, sf::Mouse::getPosition(this->game->window).y);
							this->game->window.draw(torre->getSprite());
							gObjManager.add(torre);
						}
						else
						{
							if (objMouseOver)
								std::cout << "Click en torre con UID 0x" << objMouseOver->getUID().toInt();
						}
						break;
				}
				break;
			}
			case sf::Event::MouseMoved:
			{
				objMouseOver = gObjManager.findObjectAt(sf::Mouse::getPosition(game->window));
				if (objMouseOver)
				{
					MouseCursor Cursor(MouseCursor::HAND);
					Cursor.set(game->window.getSystemHandle());
					//std::cout << "Raton en torre con UID 0x" << objMouseOver->getUID().getUID();
				}
				else
				{
					MouseCursor Cursor(MouseCursor::NORMAL);
					Cursor.set(game->window.getSystemHandle());
				}
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
