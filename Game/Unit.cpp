#include "Unit.h"
#include <iostream>

Unit::Unit()
{
}


Unit::~Unit()
{
}

void Unit::draw()
{
	animatedSprite.draw();
}

const char * Unit::getNombre()
{
	return nombre;
}

void Unit::setNombre(const char * nombreNuevo)
{
	std::cout << "setNombre(" << nombreNuevo << ")" << std::endl;
	nombre = nombreNuevo;
}

void Unit::setRutaImagen(const char * ruta)
{
	std::cout << "("<< getNombre()<<") setRutaImagen(" << ruta << ")" << std::endl;
	rutaImagen = ruta;
	if ((rutaImagen == NULL))
	{
		std::cout << "Ruta de imagen inexistente para " << getNombre() << "." << std::endl;
		return;
	}
	animatedSprite = AnimatedSprite(rutaImagen);
}