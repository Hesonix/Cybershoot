#pragma once

#include "SFML/Graphics.hpp"
#include <unordered_map>

class ResourceManager
{
private:
	std::unordered_map<std::string, sf::Texture> textures;
	std::unordered_map<std::string, sf::Font> fonts;
public:
	void Init();

	void LoadTexture(const std::string& name, const std::string& file);
	void LoadFont(const std::string& name, const std::string& file);

	sf::Texture& GetTextureByName(const std::string& name);
	sf::Font& GetFontByName(const std::string& name);
};