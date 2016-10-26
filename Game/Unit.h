#pragma once
#include "AnimatedSprite.h"

/*
	Clase padre de todas las unidades, enemigas o aliadas.
*/
class Unit
{
protected:
	const char* rutaImagen;			///< Ruta en la que encontrar la Imagen del objeto.
	const char* nombre = "";		///< Nombre del objeto.
private:
	AnimatedSprite animatedSprite;	///< Enlace a la animación del objeto.
public:
	Unit();
	~Unit();
	void draw();					///< Método que dibuja el objeto en la pantalla.
	const char* getNombre();		///< Método que devuelve el nombre del objeto.
	void setNombre(const char* nombreNuevo);	///< Método que asigna un nombre al objeto.
	void setRutaImagen(const char* ruta);		///< Método que asigna una ruta para la Imagen del objeto y genera su AnimatedSprite.
};

