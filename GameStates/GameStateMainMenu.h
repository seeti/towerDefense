#pragma once

#ifndef GameStateMainMenu_H
#define GameStateMainMenu_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "GameState.h"

class GameStateMainMenu : public GameState
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

	sf::Font fuenteMenu;
	sf::SoundBuffer bufferSonidoMenu;
	sf::Sound sonidoMenu;
	sf::Text textoOpcionMenu[3];
	bool reproducirSonido = true;

	sf::Shader shaderBackground;
	float shaderBackgroundTime = 0;

	int botonHover;

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();
	
	GameStateMainMenu(Game* game);

	//GameStateMainMenu();
	~GameStateMainMenu();
};

#endif /* GameStateMainMenu_H */
