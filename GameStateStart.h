#pragma once

#ifndef GAMESTATESTART_H
#define GAMESTATESTART_H

#include <SFML/Graphics.hpp>
#include "GameState.h"

class GameStateStart : public GameState
{






enum OpcionesMenu {
	Menu_Jugar,
	Menu_Opciones,
	Menu_Salir,
	Menu_QTY
};

const char* StringsMenu[Menu_QTY] = {
	"Jugar",
	"Opciones",
	"Salir"
};


private:
	sf::View view;
	void cargaFondo();
	void createMenu();
	void enterBuildMode();

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();
	void onTick();
	
	GameStateStart(Game* game);

	//GameStateStart();
	~GameStateStart();
};

#endif /* GAMESTATESTART_H */