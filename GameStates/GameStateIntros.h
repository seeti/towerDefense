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
	"splashLogo_1.png",
	"splashLogo_2.png"
};

private:
	void enterMainMenu();
	SettingsManager settingsManager;
	const char* logoSplashFolder = "media/logos/";

	void loadSplashFiles();

	// NOTA: Aquí antes utilizaba un std::vector, pero he tenido que cambiarlo a std::pair
	// porque destruia la textura antes de utilizarla. Recuerdame que te explique esto.
	// http://www.sfml-dev.org/tutorials/2.4/graphics-sprite.php#the-white-square-problem
	std::vector<std::pair<sf::Texture, sf::Sprite>> splashImages;
	std::pair<sf::Texture, sf::Sprite> splashImage;

	int splashDrawingNow;
	sf::Clock splashScreenShowTimeClock;
	sf::Time splashScreenShowTime;
	int alpha;

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStateIntros(Game* game);
	~GameStateIntros();
};

