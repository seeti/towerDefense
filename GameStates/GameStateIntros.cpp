#include "GameStateIntros.h"
#include "GameStateMainMenu.h"
#include "../GameAnimations/TextureManager.h"

GameStateIntros::GameStateIntros(Game* game)
{
	this->game = game;

	// Si en el config.cfg aparece la variable debugMode = 1, se salta las intros.
	if (this->game->settingsManager.getIntValueOfKey("debugMode", 0) == 1)
		this->enterMainMenu();

	this->loadSplashFiles();						// Funci�n para rellenar el vector con los logos.
	this->splashDrawingNow = 0;						// Variable para controlar que logo se tiene que dibujar.
	this->splashScreenShowTime = sf::seconds(5);	// Tiempo que queremos que se muestre el logo.
	this->alpha = 0;								// Inicializamos el alpha a 0 (totalmente transparente).
}

void GameStateIntros::loadSplashFiles()
{
	for (int i = 0; i < logoSplash_QTY; i++)
	{
		/* SOLUCIONADO EL TEMA DEL CUADRADO BLANCO, utilizando el textureManager que hay en la clase Game.
		Por lo visto se destruia la textura antes de llegar a utilizarla */
		this->game->texmgr.loadTexture("splash_" + i, this->logoSplashFolder + (std::string)urlSplash[i]);
		
		sf::Sprite sprite;

		/* Aplicamos la textura al sprite, y centramos en el RenderWindow*/
		sprite.setTexture(this->game->texmgr.getRef("splash_" + i));
		sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
		sprite.setPosition(this->game->window.getSize().x / 2, this->game->window.getSize().y / 2);
	
		/* Lo a�adimos a un contenedor que luego podremos recorrer independientemente de los
		logos que hayamos a�adido. */
		this->splashImages.push_back(sprite);
	}

	return;
}

void GameStateIntros::draw(const float dt)
{
	this->game->window.draw(this->splashImages[this->splashDrawingNow]);

	return;
}

void GameStateIntros::update(const float dt)
{
	/* En esta parte se gestiona que logo se tiene que mostrar y se aplica un fadeIn y un fadeOut */

	sf::Time timeElapsed = this->splashScreenShowTimeClock.getElapsedTime();
	while (timeElapsed.asSeconds() <= this->splashScreenShowTime.asSeconds() && alpha < 255)
	{
		this->splashImages[this->splashDrawingNow].setColor(sf::Color(255, 255, 255, this->alpha));
		this->alpha += 2;
		//this->splashScreenShowTime = -sf::seconds(0.1f);
		std::cout << this->splashScreenShowTimeClock.getElapsedTime().asSeconds() << std::endl;
	}

	this->splashScreenShowTimeClock.restart();

	return;
}

void GameStateIntros::skipSplash()
{
	if (this->splashDrawingNow < logoSplash_QTY)
	{
		this->splashDrawingNow++;
	}
	else
	{
		this->enterMainMenu();
	}	
}

void GameStateIntros::handleInput()
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

					case sf::Keyboard::Return:
						//this->enterMainMenu();
						this->skipSplash();
						break;

					case sf::Keyboard::Space:
						//this->enterMainMenu();
						this->skipSplash();
						break;

					default:
						break;
				}
			}
		}
	}

	return;
}

void GameStateIntros::enterMainMenu()
{
	this->game->pushState(new GameStateMainMenu(this->game));

	return;
}

GameStateIntros::~GameStateIntros()
{
}