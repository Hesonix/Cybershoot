#include "Pickup/Pickup.h"

#include "Player.h"
#include "Collision.h"

Pickup::Pickup(sf::Vector2f position)
{
	sprite.setScale(2.0f, 2.0f);
	sprite.setOrigin(16.0f, 16.0f);
	sprite.setPosition(position);
}

bool Pickup::DidCollideWithPlayer()
{
	return Collision::CheckRectangleCollision(GetGlobalBounds(), Player::GetInstance().GetGlobalBounds());
}

void Pickup::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite);
}