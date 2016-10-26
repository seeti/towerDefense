#include "Dragon.h"
#include "../../Game.h"

Dragon::Dragon()
{
	setNombre("Dragon prueba");
	setRutaImagen("media/unit_dragon.png");
	setPosition(gGame.screenWidth / 2, gGame.screenHeight / 2);
	setOrigin(true);
}


Dragon::~Dragon()
{
}
