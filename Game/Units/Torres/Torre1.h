#pragma once
#include "../Torre.h"

class Torre1 : public Torre
{
public:
	Torre1();
	~Torre1();
	void setNombre(const char* nombreNuevo);
	void setRutaImagen(const char* ruta);
};

