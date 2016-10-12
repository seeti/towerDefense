#pragma once

#include <functional>
#include <SFML/Graphics.hpp>
#include "GameState.h"

class GameStateIntros : public GameState
{

enum Dir { Out, In, None };

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
	const char* logoSplashFolder = "media/logos/";

	void loadSplashFiles();
	void skipSplash();

	/* Al utilizar el textureManager de la clase Game, ya no necesitamos el std::pair para hacer
	parejas de textura-sprite. Con un vector nos vale. */
	std::vector<sf::Sprite> splashImages;

	int splashDrawingNow;
	sf::Clock splashScreenShowTimeClock, splashScreenShowTimeIteration;
	sf::Time splashScreenShowTime, splashScreenTimeStep;
	Dir direction;
	int alpha;

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStateIntros(Game* game);
	~GameStateIntros();
};

