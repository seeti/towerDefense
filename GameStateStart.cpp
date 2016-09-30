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

	for (int i = 0; i < Menu_QTY; i++) {

		this->game->window.draw(textoOpcionMenu[i]);
	}

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
{
	if (!this->fuenteMenu.loadFromFile("media/big_noodle_titling_oblique.ttf"))
	{
		std::cout << "ERROR CARGANDO LA FUENTE DEL MENU" << std::endl;
		this->game->window.close();
	}

	if (!this->bufferSonidoMenu.loadFromFile("media/click.wav"))
	{
		std::cout << "ERROR CARGANDO SONIDO DEL MENU" << std::endl;
		this->game->window.close();
	}

	this->sonidoMenu.setBuffer(this->bufferSonidoMenu);
	this->sonidoMenu.setVolume(10);

	for (int i = 0; i < Menu_QTY; i++) {

		std::cout << "Opcion: " << StringsMenu[i] << std::endl;
		
		this->textoOpcionMenu[i].setFont(fuenteMenu);
		this->textoOpcionMenu[i].setString(StringsMenu[i]);
		this->textoOpcionMenu[i].setPosition(100.0f, i * 50.0f);
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
					//std::cout << "Entrando en modo building" << std::endl;
					this->enterBuildMode();
					break;
				}
			}

			case sf::Event::MouseMoved:
			{
				sf::Vector2f mousePos = sf::Vector2f((float)sf::Mouse::getPosition(this->game->window).x, (float)sf::Mouse::getPosition(this->game->window).y);
				//std::cout << "X: " << mousePos.x << " Y: " << mousePos.y << std::endl;

				for (int i = 0; i < Menu_QTY; i++) {

					sf::FloatRect textRect = textoOpcionMenu[i].getGlobalBounds();
					textoOpcionMenu[i].setCharacterSize(30);

					if (textRect.contains(mousePos))
					{
						//std::cout << "ESTA DENTRO DEL BOTON " << (std::string)textoOpcionMenu[i].getString() << std::endl;
						textoOpcionMenu[i].setCharacterSize(36);
						
						if (this->reproducirSonido)
						{
							this->sonidoMenu.play();
							this->reproducirSonido = false;
						}
					}
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
