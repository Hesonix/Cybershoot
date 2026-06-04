#include "Manager/ResourceManager.h"

void ResourceManager::LoadTexture(const std::string& name, const std::string& file)
{
	sf::Texture texture;
	texture.loadFromFile(file);
	textures[name] = texture;
}

void ResourceManager::LoadFont(const std::string& name, const std::string& file)
{
	sf::Font font;
	font.loadFromFile(file);
	fonts[name] = font;
}

sf::Texture& ResourceManager::GetTextureByName(const std::string& name)
{
	return textures[name];
} 

sf::Font& ResourceManager::GetFontByName(const std::string& name)
{
	return fonts[name];
}
