
#include "Game.h"
#include "GameStates/GameStateMainMenu.h"
#include "GameStates/GameStateIntros.h"
#include "GameObjects/ObjectManager.h"
#include "SettingsManager.h"

Game gGame;
ObjectManager gObjManager;

int main()
{
	SettingsManager stMngr("config.cfg");

	std::cout << stMngr.getIntValueOfKey("debugMode", 0) << std::endl;

	if (stMngr.getIntValueOfKey("debugMode", 0) == 0)
		gGame.pushState(new GameStateIntros(&gGame));
	else
		gGame.pushState(new GameStateMainMenu(&gGame));
	gGame.gameLoop();

	return 0;
}
