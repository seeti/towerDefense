#pragma once
#include "SFML/Graphics.hpp"
#include "Game\Unit.h"
#include "Game\TextureManager.h"

class GameManager;

extern class Game
{
private:
	GameManager* pGameManager;
	//GameState* pGameManager;
	//GameStatesManager* pGameStatesManager;
public:
	TextureManager* pTextureManager;
	int iScreenWidth;	///< Tama�o en pixeles del ancho de la pantalla.
	int iScreenHeight;	///< Tama�o en pixeles del alto de la pantalla.
	sf::RenderWindow pGameWindow;	///< Enlace a la pantalla del juego.
	void onTick();		///< M�todo que se encarga de gestionar el paso del tiempo en el juego.
	Game();
	~Game();
} gGame;

