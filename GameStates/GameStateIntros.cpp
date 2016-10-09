#include "GameStateIntros.h"
#include "GameStateMainMenu.h"

GameStateIntros::GameStateIntros(Game* game)
{
	this->game = game;

	// Si en el config.cfg aparece la variable debugMode = 1, se salta las intros.
	if (settingsManager.getIntValueOfKey("debugMode", 0) == 1)
		this->enterMainMenu();

	this->loadSplashFiles();
}

void GameStateIntros::loadSplashFiles()
{

	sf::Texture imagen;
	sf::Sprite sprite;

	for (int i = 0; i <= logoSplash_QTY; i++)
	{
		if (!imagen.loadFromFile(this->logoSplashFolder + (char)urlSplash[i]))
			std::cout << "ERROR CARGANDO EL LOGO DEL SPLASH NUM." << i << std::endl;

		sprite.setTexture(imagen);
		// Lo añadimos a un vector que luego podremos recorrer independientemente de los
		// logos que hayamos añadido
		this->splashImages.push_back(sprite);
	}

	/*  Aquí mi idea es eliminar la ultima textura y el ultimo sprite una vez que se ha
		rellenado el array, ya que no los vamos a utilizar. Pero no se si esta bien hecho.
	*/

	delete &imagen;
	delete &sprite;
}

void GameStateIntros::draw(const float dt)
{
	
}

void GameStateIntros::update(const float dt)
{

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

					case sf::Keyboard::Return || sf::Keyboard::Space:
						this->enterMainMenu();
						break;
					default:
						break;
				}
			}
		}
	}
}

void GameStateIntros::enterMainMenu()
{
	this->game->pushState(new GameStateMainMenu(this->game));

	return;
}

GameStateIntros::~GameStateIntros()
{
}
