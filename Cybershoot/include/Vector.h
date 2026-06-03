#pragma once

#include <cmath>

#include "SFML/System/Vector2.hpp"

class Vector
{
public:
	static float Length(sf::Vector2f v);
	static sf::Vector2f Normalize(sf::Vector2f v);
	static float Distance(sf::Vector2f a, sf::Vector2f b);
	static float DistanceSquared(sf::Vector2f a, sf::Vector2f b);
	static sf::Vector2f Rotate(sf::Vector2f v, float angleRadians);
};










