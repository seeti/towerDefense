#pragma once

#include "GameState.h"
#include "ObjBase.h"
#include "Animation.h"

enum class ActionState {NONE, HUMAN, FIRE, WATER, BUILDING};

class GameStatePlay : public GameState
{
private:
	ActionState actionState;

	sf::View gameView;
	sf::View guiView;

	void leaveBuildMode();
	ObjBase* objMouseOver;	// El puntero del ratón se encuentra encima de este objeto dinámico.
	sf::CircleShape rangeCircle;

	// De momento lo dejo comentado y ya haremos pruebas
	//Animation prueba;
	//AnimatedSprite pruebix;

public:

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStatePlay(Game* game);
	~GameStatePlay();
};

