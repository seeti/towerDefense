#pragma once
#include "AnimatedObject.h"
#include <Windows.h>

class Torre : public AnimatedObject
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
	virtual bool placeAt(int x, int y, bool bIgnoreChecks = false);
};

