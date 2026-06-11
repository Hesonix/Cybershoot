#pragma once

#include "SFML/Graphics.hpp"

#include "WindowSettings.h"

class Camera
{
private:
	static constexpr float DEADZONE_X = 100.0f;
	static constexpr float DEADZONE_Y = 100.0f;
	static constexpr float SMOOTH_SPEED = 0.025f;

	sf::View view;
public:
	Camera();

	void SetPosition(sf::Vector2f position);

	void Update(sf::Vector2f playerPosition);

	sf::Vector2f GetPosition() { return view.getCenter(); }
	
	sf::View& GetView() { return view; }
};