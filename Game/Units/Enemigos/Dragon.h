#pragma once
#include "../Enemigo.h"

class Dragon : public Enemigo
{
public:
	Dragon();
	~Dragon();
	void setNombre(const char* nombreNuevo);
	void setRutaImagen(const char* ruta);
};

