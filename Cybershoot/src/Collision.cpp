#include "Collision.h"

#include "Util/Vector.h"

bool Collision::CheckCircleCollision(sf::Vector2f center1, float radius1, sf::Vector2f center2, float radius2)
{
	float radiiSum = radius1 + radius2;
	return Vector::DistanceSquared(center1, center2) <= (radiiSum * radiiSum);
}

bool Collision::CheckRectangleCollision(sf::FloatRect rectangle1, sf::FloatRect rectangle2)
{
	return rectangle1.intersects(rectangle2);
}