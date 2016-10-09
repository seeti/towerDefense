#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "../SettingsManager.h"

class GameStateIntros : public GameState
{

enum logoSplash {
	logoSplash_1,
	logoSplash_2,
	logoSplash_QTY
};

const char* urlSplash[logoSplash_QTY] = {
	"logoSplash_1.png",
	"logoSplash_2.png"
};

private:
	void enterMainMenu();
	SettingsManager settingsManager;
	const char* logoSplashFolder = "../media/logos/";

	void loadSplashFiles();
	std::vector<sf::Sprite> splashImages;

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStateIntros(Game* game);
	~GameStateIntros();
};

