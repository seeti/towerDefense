#include "TextureManager.h"
#include <iostream>



sf::Texture TextureManager::loadFromFile(std::string nombre, const char * file) {
	if (exists(nombre))	// Si ya est� cargada, se detiene el c�digo.
		return getRef(nombre);
	sf::Texture textura;
	textura.loadFromFile(file);	// Si no puede cargarla, return false.

	add(nombre, textura);	// A�ade la textura.
	return getRef(nombre);
}

TextureManager::TextureManager() {

}


TextureManager::~TextureManager() {

}

void TextureManager::add(std::string nombre, sf::Texture textura) {
	(*this)[nombre] = textura;
}

sf::Texture TextureManager::getRef(std::string textura) {
	return at(textura);
}

bool TextureManager::exists(std::string textura) {
	return count(textura) > 0;
}