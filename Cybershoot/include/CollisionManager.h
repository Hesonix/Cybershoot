#pragma once

#include "SFML/Graphics.hpp"

class CollisionManager
{
private:
	bool CheckCircleCollision(sf::Vector2f center1, float radius1, sf::Vector2f center2, float radius2);
	bool CheckRectangleCollision(sf::FloatRect rectangle1 , sf::FloatRect rectangle2);
public:
	void Update();
};