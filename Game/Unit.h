#pragma once
#include "AnimatedSprite.h"

class Unit
{
protected:
	const char* rutaImagen = "media/unit_dragon.png";
private:
	AnimatedSprite animatedSprite;
public:
	Unit();
	~Unit();
	void draw();
};

