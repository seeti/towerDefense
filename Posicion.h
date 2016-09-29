#pragma once
struct Posicion
{
public:
	int x;
	int y;
	Posicion();
	~Posicion();
	bool moveTo(int x, int y);
};

