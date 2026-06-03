#include "CollisionManager.h"
#include "ManagerLocator.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "Player.h"
#include "UIManager.h"
#include "Vector.h"
#include "PickupManager.h"

bool CollisionManager::CheckCircleCollision(sf::Vector2f center1, float radius1, sf::Vector2f center2, float radius2)
{
	float radiiSum = radius1 + radius2;
	return Vector::DistanceSquared(center1, center2) <= (radiiSum * radiiSum);
}

bool CollisionManager::CheckRectangleCollision(sf::FloatRect rectangle1, sf::FloatRect rectangle2)
{
	return rectangle1.intersects(rectangle2);
}

void CollisionManager::Update()
{
	auto& bullets = ManagerLocator::GetBulletManager().GetBullets();
	auto& enemies = ManagerLocator::GetEnemyManager().GetEnemies();
	auto& pickups = ManagerLocator::GetPickupManager().GetPickups();

	for (auto& bullet : bullets)
	{
		bool isOwnedByPlayer = bullet->IsOwnedByPlayer();

		for (auto& enemy : enemies)
		{
			bool didCollideWithEnemy = CheckRectangleCollision(bullet->GetGlobalBounds(), enemy->GetGlobalBounds());
			if (isOwnedByPlayer && didCollideWithEnemy)
			{
				bullet->Destroy();
				enemy->Destroy();
				break;
			}
		}

		bool didCollideWithPlayer = CheckRectangleCollision(bullet->GetGlobalBounds(), Player::GetInstance().GetGlobalBounds());
		if (!isOwnedByPlayer && didCollideWithPlayer)
		{
			bullet->Destroy();
			Player::GetInstance().TakeDamage(10);
		}
	}

	for (auto& pickup : pickups)
	{
		if (CheckRectangleCollision(Player::GetInstance().GetGlobalBounds(), pickup->GetGlobalBounds()))
		{
			pickup->Collect();
		}
	}
}