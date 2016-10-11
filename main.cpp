#include "Game.h"
//#include "GameStates/GameStateMainMenu.h"
#include "GameStates/GameStateIntros.h"
#include "GameObjects/ObjectManager.h"

Game gGame;
ObjectManager gObjManager;

int main()
{

	gGame.pushState(new GameStateIntros(&gGame));
	gGame.gameLoop();

	return 0;
}