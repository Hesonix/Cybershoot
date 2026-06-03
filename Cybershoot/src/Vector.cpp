#include "Vector.h"

float Vector::Length(sf::Vector2f v)
{
	return std::sqrt(v.x * v.x + v.y * v.y);
}

sf::Vector2f Vector::Normalize(sf::Vector2f v)
{
	float length = Length(v);
	if (length != 0)
	{
		return { v.x / length, v.y / length };
	}
	return sf::Vector2f(0, 0);
}

float Vector::Distance(sf::Vector2f a, sf::Vector2f b)
{
	return Length(a - b);
}

float Vector::DistanceSquared(sf::Vector2f a, sf::Vector2f b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float distanceSquared = dx * dx + dy * dy;
	return distanceSquared;
}

sf::Vector2f Vector::Rotate(sf::Vector2f v, float angleRadians)
{
	float cosAngle = cos(angleRadians);
	float sinAngle = sin(angleRadians);

	return sf::Vector2f(
		v.x * cosAngle - v.y * sinAngle,
		v.x * sinAngle + v.y * cosAngle
	);
}




