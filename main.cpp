#include "Game.h"


Game gGame; //Creamos una instancia de la clase Game

void main()
{
	while (gGame.window.isOpen())
	{
		gGame.window.clear();
		gGame.onTick();
		gGame.window.display();
	}
	return;
}