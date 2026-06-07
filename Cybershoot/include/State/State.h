#pragma once

#include "SFML/Graphics.hpp"

class State
{
public:
	virtual ~State() = default;
	virtual void HandleInput(sf::Event& event, sf::RenderWindow& window) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow& window) = 0;
};