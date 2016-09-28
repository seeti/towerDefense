#include "Game.h"
#include "GameStateStart.h"
#include "ObjectManager.h"

Game gGame;
ObjectManager gObjManager;

int main()
{

	gGame.pushState(new GameStateStart(&gGame));
	gGame.gameLoop();

	return 0;
}