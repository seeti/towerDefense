#pragma once
#include "AnimatedSprite.h"

class Unit
{
protected:
	const char* rutaImagen;
	const char* nombre = "";
private:
	AnimatedSprite animatedSprite;
public:
	Unit();
	~Unit();
	void draw();
	const char* getName();
	virtual void setNombre(const char* nombreNuevo) = 0;
	virtual void setRutaImagen(const char* ruta) = 0;
};

