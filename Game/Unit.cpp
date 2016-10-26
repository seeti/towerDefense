#include "Unit.h"
#include <iostream>

Unit::Unit()
{
	if ((rutaImagen == NULL))
	{
		std::cout << "Ruta de imagen inexistente para " << getName() << "." << std::endl;
		return;
	}
	animatedSprite = AnimatedSprite(rutaImagen);
}


Unit::~Unit()
{
}

void Unit::draw()
{
	animatedSprite.draw();
}

const char * Unit::getName()
{
	return nombre;
}

void Unit::setNombre(const char * nombreNuevo)
{
	std::cout << "setNombre(" << nombreNuevo << ")" << std::endl;
	nombre = nombreNuevo;
}
