#pragma once

#include "SFML/Graphics.hpp"
#include "Camera.h"

class RenderManager
{
private:
	sf::RenderWindow window;
	Camera camera;
public:
	RenderManager();

	sf::Vector2i GetMousePosition();
	sf::Vector2f GetMouseWorldPosition();

	sf::RenderWindow& GetWindow() { return window; }
	Camera& GetCamera() { return camera; }
};