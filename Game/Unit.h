#pragma once
#include "AnimatedSprite.h"

/*
	Clase padre de todas las unidades, enemigas o aliadas.
*/
class Unit
{
protected:
	const char* rutaImagen;				///< Ruta en la que encontrar la Imagen del objeto.
	const char* nombre = "";			///< Nombre del objeto.
private:
	AnimatedSprite animatedSprite;		///< Enlace a la animaci�n del objeto.
public:
	Unit();
	~Unit();
	void draw(const float elapsed);							///< M�todo que dibuja el objeto en la pantalla.
	const char* getNombre();								///< M�todo que devuelve el nombre del objeto.
	void setNombre(const char* nombreNuevo);				///< M�todo que asigna un nombre al objeto.
	void setRutaImagen(const char* ruta);					///< M�todo que asigna una ruta para la Imagen del objeto y genera su AnimatedSprite.
	void setPosition(float x, float y);						///< M�todo que asigna la posici�n del sprite
	void setOrigin(bool centered = true);					///< M�todo que mueve el origen de la esquina top-left al center del sprite
	void setOrigin(float x, float y);						///< M�todo sobrecargado para mover el origen a las coordenadas especificadas
	void setDireccion(int dir);								///< M�todo que define la direcci�n de la animaci�n del objeto
	virtual bool onTick(const float elapsed) = 0;
};

