#include "GameStateIntros.h"
#include "GameStateMainMenu.h"

GameStateIntros::GameStateIntros(Game* game)
{
	this->game = game;

	// Si en el config.cfg aparece la variable debugMode = 1, se salta las intros.
	if (settingsManager.getIntValueOfKey("debugMode", 0) == 1)
		this->enterMainMenu();

	this->loadSplashFiles();						// Función para rellenar el vector con los logos.
	this->splashDrawingNow = 0;						// Variable para controlar que logo se tiene que dibujar.
	this->splashScreenShowTime = sf::seconds(2.f);	// Tiempo que queremos que se muestre el logo.
	this->alpha = 0;								// Inicializamos el alpha a 0 (totalmente transparente).
}

void GameStateIntros::loadSplashFiles()
{
	for (int i = 0; i < logoSplash_QTY; i++)
	{
		sf::Texture imagen;
		sf::Sprite sprite;

		if (!imagen.loadFromFile(this->logoSplashFolder + (std::string)urlSplash[i]))
			std::cout << "ERROR CARGANDO EL LOGO DEL SPLASH NUM." << i << std::endl;

		/* Aplicamos la textura al sprite, y centramos en el RenderWindow*/
		sprite.setTexture(imagen);
		sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
		sprite.setPosition(this->game->window.getSize().x / 2, this->game->window.getSize().y / 2);

		/* Lo añadimos a un contenedor que luego podremos recorrer independientemente de los
		logos que hayamos añadido. */
		this->splashImage = std::make_pair(imagen, sprite);
		this->splashImages.push_back(this->splashImage);
	}

	/*  Aquí mi idea es eliminar la ultima textura y el ultimo sprite una vez que se ha
		rellenado el array, ya que no los vamos a utilizar. Pero no se si esta bien hecho. */

	//delete &imagen;
	//delete &sprite;

	return;
}

void GameStateIntros::draw(const float dt)
{
	//this->game->window.draw(this->splashImages[0].second);
	this->game->window.draw(this->splashImages[this->splashDrawingNow].second);

	return;
}

void GameStateIntros::update(const float dt)
{
	/* En esta parte se gestiona que logo se tiene que mostrar y se aplica un fadeIn y un fadeOut */

	sf::Time timeElapsed = this->splashScreenShowTimeClock.getElapsedTime();
	while (timeElapsed.asSeconds() <= this->splashScreenShowTime.asSeconds() && alpha < 255)
	{
		this->splashImages[this->splashDrawingNow].second.setColor(sf::Color(255, 255, 255, this->alpha++));
		//this->splashScreenShowTime = -sf::seconds(0.1f);
		std::cout << this->alpha << std::endl;
	}

	this->splashScreenShowTimeClock.restart();

	return;
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
						this->enterMainMenu();
						break;

					case sf::Keyboard::Space:
						this->enterMainMenu();
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
