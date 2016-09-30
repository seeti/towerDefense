#include "GameStateStart.h"
#include "GameStateBuilding.h"
#include <iostream>
#include <array>

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
	this->game->background.setTexture(this->game->texmgr.getRef("background"));
}

void GameStateStart::createMenu()
{	sf::Font fuenteMenu;
	if (!fuenteMenu.loadFromFile("media/big_noodle_titling_oblique.ttf"))
	{
		std::cout << (std::string)var << std::endl;
		std::cout << "ERROR CARGANDO LA FUENTE DEL MENU" << std::endl;
	}


	for (int i = 0; i < Menu_QTY ; i++) {

		std::cout << "Opcion: " << StringsMenu[i] << std::endl;
		sf::RectangleShape rectBoton;
		sf::Text textoOpcionMenu;
		textoOpcionMenu.setFont(fuenteMenu);
		textoOpcionMenu.setString(StringsMenu[i]);
		textoOpcionMenu.setPosition(100, 100);
		this->game->window.draw(textoOpcionMenu);
	}
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

void GameStateStart::onTick()
{
}

void GameStateStart::enterBuildMode()
{
	this->game->pushState(new GameStateBuilding(this->game));

	return;
}

GameStateStart::~GameStateStart()
{
}
