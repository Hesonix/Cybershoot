#include "Manager/ResourceManager.h"

void ResourceManager::Init()
{
	LoadFont("UI", "res/fonts/Tiny5-Regular.ttf");
	LoadTexture("floor", "res/textures/floor.png");
	LoadTexture("player", "res/textures/player.png");
	LoadTexture("pistol", "res/textures/pistol.png");
	LoadTexture("bullet", "res/textures/bullet.png");
	LoadTexture("grunt", "res/textures/grunt.png");
	LoadTexture("mortar", "res/textures/mortar.png");
	LoadTexture("bull", "res/textures/bull.png");
	LoadTexture("ammo_pickup", "res/textures/ammo_pickup.png");
	LoadTexture("health_pickup", "res/textures/health_pickup.png");
}

void ResourceManager::LoadTexture(const std::string& name, const std::string& file)
{
	sf::Texture texture;
	if (texture.loadFromFile(file))
	{
		textures.emplace(name, std::move(texture));
	}
	
}

void ResourceManager::LoadFont(const std::string& name, const std::string& file)
{
	sf::Font font;
	if (font.loadFromFile(file))
	{
		fonts.emplace(name, std::move(font));
	}
}

sf::Texture& ResourceManager::GetTextureByName(const std::string& name)
{
	return textures[name];
} 

sf::Font& ResourceManager::GetFontByName(const std::string& name)
{
	return fonts[name];
}
