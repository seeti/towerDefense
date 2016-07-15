#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Tower
{
	public:
		Tower(sf::RenderWindow& window);
		~Tower();

	public:
		void Tower::dibujaTorreta();

	private:
		sf::RenderWindow& mWindow;
		sf::Texture textura;
		sf::Sprite spriteEagle;
};

