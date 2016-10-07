#pragma once
#include "ObjBase.h"
#include <Windows.h>

class Torre : public ObjBase
{
private:
	sf::Texture sfTexture;
	const float primaryAttack = 1.250;
	float elapsedPrimaryAttack = 0;
public:
	Torre();
	~Torre();
	bool onTick(const float dt);
	bool moveTo(int x, int y);
	void onLoadTexture();
	virtual const char* getObjectName();
	virtual char* getIconSrc();
};

