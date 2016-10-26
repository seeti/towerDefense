#include "Game.h"


Game gGame; //Creamos una instancia de la clase Game

void main()
{
	sf::Event event;
	while (gGame.window.isOpen())
	{
		while (gGame.window.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed)
				gGame.window.close();
		}
		gGame.window.clear();
		gGame.onTick();
		gGame.window.display();
	}
	return;
}