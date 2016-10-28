#pragma once
#include <map>
#include <SFML\Graphics\Texture.hpp>

class TextureManager : public std::map<std::string, sf::Texture>
{
private:
	void add(std::string nombre, sf::Texture textura);	///< Añade la textura 'textura' con el nombre 'nombre'.
	sf::Texture getRef(std::string textura);		// Devuelve la textura 'textura'.
	bool exists(std::string textura);				// Busca la textura 'textura'.
public:
	sf::Texture loadFromFile(std::string nombre, const char* file);	///< Intenta cargar la Texture 'file' bajo el nombre 'nombre' y la devuelve.
	TextureManager();
	~TextureManager();
};

