#include "GameStateMainMenu.h"
#include "GameStatePlay.h"
#include <iostream>
#include <array>

GameStateMainMenu::GameStateMainMenu(Game* game)
{
	this->game = game;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->view.setSize(pos);
	pos *= 0.5f;
	this->view.setCenter(pos);
	this->botonHover = Menu_QTY;

	this->cargaFondo();
	this->createMenu();
}

void GameStateMainMenu::draw(const float dt)
{
	this->game->window.setView(this->view);

	this->game->window.clear(sf::Color::Black);
	this->game->window.draw(this->game->background);

	for (int i = 0; i < Menu_QTY; i++) {

		this->game->window.draw(textoOpcionMenu[i]);
	}

	return;
}

void GameStateMainMenu::update(const float dt)
{
}

void GameStateMainMenu::cargaFondo()
{
	this->game->background.setTexture(this->game->texmgr.getRef("background"));
}

void GameStateMainMenu::createMenu()
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

	int screenWidth = game->settingsManager.getIntValueOfKey("ScreenWidth", 1280);
	int screenHeight = game->settingsManager.getIntValueOfKey("ScreenHeight", 720);

	for (int i = 0; i < Menu_QTY; i++) {

		this->textoOpcionMenu[i].setFont(fuenteMenu);
		this->textoOpcionMenu[i].setString(StringsMenu[i]);
		this->textoOpcionMenu[i].setPosition(screenWidth * 0.1, ((screenHeight * 0.8) + i * screenHeight * 0.05));
	}
}

void GameStateMainMenu::handleInput()
{
	sf::Event event;

	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
			/* Close the window */
			case sf::Event::Closed:
			{
				this->game->window.close();
				break;
			}
			
			case sf::Event::KeyPressed:
			{
				switch (event.key.code)
				{
					case sf::Keyboard::Escape:
						this->game->window.close();
						break;

					case sf::Keyboard::L:
						this->enterBuildMode();
						break;
					default:
						break;
				}
			}

			case sf::Event::MouseButtonPressed:
			{
				if (event.mouseButton.button == sf::Mouse::Left || this->botonHover == OpcionesMenu::Menu_QTY)	// No nos importan los clicks con el botón derecho.
					break;
				switch (this->botonHover)
				{
					case OpcionesMenu::Menu_Jugar:
						this->enterBuildMode();
						break;

					case OpcionesMenu::Menu_Salir:
						this->game->window.close();
						break;
					default:
						break;
				}
			}

			case sf::Event::MouseMoved:
			{
				sf::Vector2f mousePos = sf::Vector2f((float)sf::Mouse::getPosition(this->game->window).x, (float)sf::Mouse::getPosition(this->game->window).y);

				for (int i = 0; i < Menu_QTY; i++) {

					sf::FloatRect textRect = textoOpcionMenu[i].getGlobalBounds();
					textoOpcionMenu[i].setCharacterSize( this->game->settingsManager.getIntValueOfKey("ScreenHeight", 720) * 0.05 );

					if (textRect.contains(mousePos))
					{
						textoOpcionMenu[i].setCharacterSize( this->game->settingsManager.getIntValueOfKey("ScreenHeight", 720) * 0.06 );
						
						if (this->reproducirSonido && this->botonHover != i)
						{
							this->sonidoMenu.play();
						}

						this->botonHover = i;
						break;	// Encontrado botón, no necesitamos recorrer más código.

					}
				}
				this->botonHover = Menu_QTY;	// No hemos encontrado botón, reseteamos el atributo en caso de que haya tenido algún otro valor anteriormente.
				break;
			}
			default:
				break;
		}
	}

	return;
}

void GameStateMainMenu::enterBuildMode()
{
	this->game->pushState(new GameStatePlay(this->game));

	return;
}

GameStateMainMenu::~GameStateMainMenu()
{
}
