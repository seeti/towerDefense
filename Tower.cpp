#include "Tower.h"

Tower::Tower(sf::RenderWindow& window)
: mWindow(window)
{	
	if (!textura.loadFromFile("Eagle.png"))
	{
		std::cout << "Error cargando la imagen." << std::endl;
	}
	else
	{
		spriteEagle.setTexture(textura);
		std::cout << "Textura cargada correctamente." << std::endl;
	}
}

void Tower::dibujaTorreta()
{
	spriteEagle.setPosition(sf::Mouse::getPosition(mWindow).x, sf::Mouse::getPosition(mWindow).y);
	std::cout << "X: " << sf::Mouse::getPosition(mWindow).x << std::endl;
	std::cout << "Y: " << sf::Mouse::getPosition(mWindow).y << std::endl;

	//mWindow.clear();
	mWindow.draw(spriteEagle);
	//mWindow.display();
}

Tower::~Tower()
{
}
