#pragma once

#include "SFML/System/Vector2.hpp"

inline float Lerp(float a, float b, float t)
{
	return a + (b - a) * t;
}

inline sf::Vector2f Lerp(sf::Vector2f a, sf::Vector2f b, float t)
{
	return a + (b - a) * t;
}