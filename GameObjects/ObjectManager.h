#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "../Game.h"
#include "ObjBase.h"
#include "UID.h"

/*
	@Brief: Clase que se encarga de recorrer todos los Objetos existentes en el juego y de hacerles saber que tienen que hacer cosas.
*/
extern class ObjectManager : public UID
{
private:
	std::vector<ObjBase*> mList;	// Lista vectoriana que almacena todos los Objetos dinámicos existentes.
public:
	ObjectManager();
	~ObjectManager();
	/*
		@Brief: Añade un elemento a la lista.
	*/
	void add(ObjBase* obj);

	/*
		@brief: Borra un elemento de la lista.
		@param Obj: objeto a añadir.
	*/
	void remove(ObjBase* obj);

	/*
		@Brief: Loop que recorre todos los objetos y les hace un onTick, para que hagan sus cosas.
		@param Obj: objeto a borrar.
	*/
	void onTick(const float dt);

	/*
		@brief: Busca un objeto en las coordenadas dadas (generalmente para obtener el objeto en el que se encuentra el cursor del ratón).
		@param Game: puntero al juego (mayormente para tener un acceso a la ventana 'window' del programa).
	*/
	ObjBase* findObjectAt(sf::Vector2i pos);

	/*
		@brief: Comprueba si hay algun objeto que colisione con el introducido como parámetro
		@param obj: objeto a comprobar
		return: el objeto con el que se colisionaría
	*/
	ObjBase* checkCollision(ObjBase* obj);
	
	/*
		@brief: devuelve la siguiente UID libre
		return: UID a asignar
	*/
	UID generateUID();

	void draw(Game* game, const float dt = 0.0f );
} gObjManager;

