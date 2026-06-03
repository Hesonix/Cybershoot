#include "BulletManager.h"

void BulletManager::SpawnBullet(sf::Vector2f position, sf::Vector2f velocity, bool isOwnedByPlayer)
{
	bullets.push_back(std::make_unique<Bullet>(position, velocity, isOwnedByPlayer));
}

void BulletManager::Cleanup()
{
	bullets.erase(
		std::remove_if(bullets.begin(), bullets.end(),
			[](auto& bullet) { return !bullet->IsAlive(); }),
		bullets.end()
	);
}

std::vector<std::unique_ptr<Bullet>>& BulletManager::GetBullets()
{
	return bullets;
}

void BulletManager::Update(float deltaTime)
{
	Cleanup();

	for (auto& bullet : bullets)
	{
		bullet->Update(deltaTime);
	}
}

void BulletManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const auto& bullet : bullets)
	{
		target.draw(*bullet);
	}
}