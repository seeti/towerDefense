#pragma once
#include "../Unit.h"

class Enemigo : public Unit
{
public:
	Enemigo();
	~Enemigo();
	virtual void setNombre(const char* nombreNuevo) = 0;
	virtual void setRutaImagen(const char* ruta) = 0;
};

