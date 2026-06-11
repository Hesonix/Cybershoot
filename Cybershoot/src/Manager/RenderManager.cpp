#include "Manager/RenderManager.h"
#include "WindowSettings.h"

RenderManager::RenderManager()
	: window(sf::VideoMode(WindowSettings::WIDTH, WindowSettings::HEIGHT), "Cybershoot", sf::Style::Fullscreen)
{
	window.setVerticalSyncEnabled(true);
}

sf::Vector2i RenderManager::GetMousePosition()
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	return mousePosition;
}

sf::Vector2f RenderManager::GetMouseWorldPosition()
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f mouseWorldPosition = window.mapPixelToCoords(mousePosition, camera.GetView());
	return mouseWorldPosition;
}