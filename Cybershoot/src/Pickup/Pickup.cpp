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

void Pickup::Update(float deltaTime)
{
	lifetime += deltaTime;

	if (lifetime >= BLINK_START_TIME)
	{
		blinkTimer += deltaTime;

		if (blinkTimer >= BLINK_INTERVAL)
		{
			blinkTimer = 0.0f;
			isVisible = !isVisible;
		}
	}

	if (lifetime >= MAX_LIFETIME)
	{
		isAlive = false;
	}
}

void Pickup::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (isVisible)
	{
		target.draw(sprite);
	}
}