#include "Bullet.h"
#include "ManagerLocator.h"
#include "ResourceManager.h"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f velocity, bool isOwnedByPlayer)
	: velocity(velocity)
	, isOwnedByPlayer(isOwnedByPlayer)
{
	sprite.setOrigin(8.0f, 8.0f);
	sprite.setPosition(position);
	sprite.setTexture(ManagerLocator::GetResourceManager().GetTextureByName("bullet"));
}

void Bullet::Update(float deltaTime)
{
	sprite.move(velocity * deltaTime);

	lifetime += deltaTime;
	if (lifetime > MAX_LIFETIME)
	{
		Destroy();
	}
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite);
}