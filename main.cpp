#include "Game.h"
#include "GameStateMainMenu.h"
#include "ObjectManager.h"

Game gGame;
ObjectManager gObjManager;

int main()
{

	gGame.pushState(new GameStateMainMenu(&gGame));
	gGame.gameLoop();

	return 0;
}