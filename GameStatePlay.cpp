#include <iostream>
#include "GameStateMainMenu.h"
#include "GameStatePlay.h"
#include "Game.h"
#include "ObjectManager.h"
#include "Torre.h"
#include "MouseCursor.h"

GameStatePlay::GameStatePlay(Game* game)
{
	this->game = game;
	this->actionState = ActionState::NONE;

	this->game->texmgr.loadTexture("background-building", "media/background_building.jpg");
	this->game->backgroundBuilding.setTexture(this->game->texmgr.getRef("background-building"));
	objMouseOver = NULL;

	// Inicialización del circulo que indica el rango de la torre
	//this->rangeCircle.setRadius(100.f);
	this->rangeCircle.setFillColor(sf::Color(200, 0, 0, 50));
	this->rangeCircle.setOutlineColor(sf::Color(200, 0, 0));
	this->rangeCircle.setOutlineThickness(1);
	//this->rangeCircle.setOrigin(this->rangeCircle.getGlobalBounds().height / 2, this->rangeCircle.getGlobalBounds().width / 2);
}

void GameStatePlay::draw(const float dt)
{
	this->game->window.clear(sf::Color::Black);
	//this->game->window.setView(this->gameView);
	this->game->window.draw(this->game->backgroundBuilding);
	gObjManager.onTick(game);
	if (placingObject)
	{
		game->window.setMouseCursorVisible(false);	//al regenerar la pantalla se asigna de nuevo a true de manera automática, no es necesario deshacer esta linea.
		sf::Texture texture;
		if (!texture.loadFromFile(placingObject->getIconSrc()))
			return;
		game->window.draw(placingObject->getSprite());
	}

	if (showRangeCircle)
		game->window.draw(this->rangeCircle);
}

void GameStatePlay::update(const float dt)
{
}

void GameStatePlay::handleInput()
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

						if (placingObject)
						{
							delete placingObject;
							this->actionState = ActionState::NONE;
							break;
						}
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
						placingObject = new Torre();
						placingObject->placeAt(sf::Mouse::getPosition(this->game->window).x, sf::Mouse::getPosition(this->game->window).y);
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
							this->actionState = ActionState::NONE;
							Torre* torre = (Torre*)placingObject;
							torre->placeAt(sf::Mouse::getPosition(this->game->window).x, sf::Mouse::getPosition(this->game->window).y);
							game->window.draw(torre->getSprite());
							placingObject = nullptr;
							gObjManager.add(torre);
							std::cout << "Action = Emplaza torre en " << torre->getSprite().getPosition().x << "/" << torre->getSprite().getPosition().y << std::endl;
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
				if (placingObject)
				{
					placingObject->placeAt(sf::Mouse::getPosition(this->game->window).x, sf::Mouse::getPosition(this->game->window).y, objMouseOver ? false : true);
					break;
				}
				if (objMouseOver)
				{
					MouseCursor Cursor(MouseCursor::HAND);
					Cursor.set(game->window.getSystemHandle());
					//std::cout << "Raton en torre con UID 0x" << objMouseOver->getUID().getUID();

					// TODO: El rango se obtendrá mediante la torre, dependiendo su tipo
					this->rangeCircle.setRadius(100.f);
					this->rangeCircle.setPosition(objMouseOver->p.x, objMouseOver->p.y);
					this->rangeCircle.setOrigin(this->rangeCircle.getGlobalBounds().height / 2, this->rangeCircle.getGlobalBounds().width / 2);

					showRangeCircle = true;
				}
				else
				{
					MouseCursor Cursor(MouseCursor::NORMAL);
					Cursor.set(game->window.getSystemHandle());

					showRangeCircle = false;
				}
			}
		}
	}
}

void GameStatePlay::leaveBuildMode()
{
	this->game->pushState(new GameStateMainMenu(this->game));

	return;
}

GameStatePlay::~GameStatePlay()
{
}
