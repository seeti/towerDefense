#pragma once
#include "ObjBase.h"
#include <Windows.h>

class Torre : public ObjBase
{
private:
	sf::Texture sfTexture;
public:
	Torre();
	~Torre();
	bool onTick();
	bool moveTo(int x, int y);
	void onLoadTexture();
	virtual const char* getObjectName();
	virtual char* getIconSrc();
};

