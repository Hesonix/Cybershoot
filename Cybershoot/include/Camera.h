#pragma once

#include "SFML/Graphics.hpp"

class Camera
{
private:
	static constexpr float SMOOTH_SPEED = 0.1f;

	sf::View view;
public:
	Camera();

	void SetPosition(sf::Vector2f position);

	void Update(sf::Vector2f newPosition);

	sf::View& GetView() { return view; }
};