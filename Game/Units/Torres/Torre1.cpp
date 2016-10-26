#include "Torre1.h"



Torre1::Torre1()
{
	setNombre("Torre prueba");
	setRutaImagen("media/unit_dragon.png");
}


Torre1::~Torre1()
{
}

void Torre1::setNombre(const char * nombreNuevo)
{
	nombre = nombreNuevo;
}

void Torre1::setRutaImagen(const char * ruta)
{
	rutaImagen = ruta;
}
