#include "Unit.h"

Unit::Unit()
{
	animatedSprite = AnimatedSprite(rutaImagen);
}


Unit::~Unit()
{
}

void Unit::draw()
{
	animatedSprite.draw();
}
