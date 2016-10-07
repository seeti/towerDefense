#include "Game.h"
#include "GameStates/GameStateMainMenu.h"
#include "GameObjects/ObjectManager.h"

Game gGame;
ObjectManager gObjManager;

int main()
{

	gGame.pushState(new GameStateMainMenu(&gGame));
	gGame.gameLoop();

	return 0;
}