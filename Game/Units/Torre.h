#pragma once
#include "../Unit.h"

class Torre : public Unit
{
public:
	Torre();
	~Torre();
	virtual void setNombre(const char* nombreNuevo) = 0;
	virtual void setRutaImagen(const char* ruta) = 0;
};

