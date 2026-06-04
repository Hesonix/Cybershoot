#include "SFML/Graphics.hpp"

class Collision
{
public:
	static bool CheckCircleCollision(sf::Vector2f center1, float radius1, sf::Vector2f center2, float radius2);
	static bool CheckRectangleCollision(sf::FloatRect rectangle1, sf::FloatRect rectangle2);
};