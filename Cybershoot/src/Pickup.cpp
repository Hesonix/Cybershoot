#include "Pickup.h"

Pickup::Pickup(sf::Vector2f position)
{
	sprite.setScale(2.0f, 2.0f);
	sprite.setOrigin(16.0f, 16.0f);
	sprite.setPosition(position);
}

void Pickup::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite);
}