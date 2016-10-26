#include "Dragon.h"

Dragon::Dragon()
{
	setNombre("Dragon prueba");
	setRutaImagen("media/unit_dragon.png");
}


Dragon::~Dragon()
{
}

void Dragon::setNombre(const char * nombreNuevo)
{
	nombre = nombreNuevo;
}

void Dragon::setRutaImagen(const char * ruta)
{
	rutaImagen = ruta;
}
