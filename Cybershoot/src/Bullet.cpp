#include "Bullet.h"
#include "Player.h"
#include "ManagerLocator.h"
#include "Manager/ResourceManager.h"
#include "Collision.h"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f velocity, bool isOwnedByPlayer)
	: velocity(velocity)
	, isOwnedByPlayer(isOwnedByPlayer)
{
	sprite.setOrigin(8.0f, 8.0f);
	sprite.setPosition(position);
	sprite.setTexture(ManagerLocator::GetResourceManager().GetTextureByName("bullet"));
}

bool Bullet::DidCollideWithEnemy(Enemy& enemy)
{
	return Collision::CheckRectangleCollision(GetGlobalBounds(), enemy.GetGlobalBounds());
}

bool Bullet::DidCollideWithPlayer()
{
	return Collision::CheckRectangleCollision(GetGlobalBounds(), Player::GetInstance().GetGlobalBounds());
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