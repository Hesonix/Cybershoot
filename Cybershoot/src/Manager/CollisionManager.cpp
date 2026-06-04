#include "Manager/CollisionManager.h"

#include "Player.h"
#include "ManagerLocator.h"
#include "Manager/BulletManager.h"
#include "Manager/EnemyManager.h"
#include "Manager/PickupManager.h"

void CollisionManager::Update(float deltaTime)
{
	auto& bullets = ManagerLocator::GetBulletManager().GetBullets();
	auto& enemies = ManagerLocator::GetEnemyManager().GetEnemies();
	auto& pickups = ManagerLocator::GetPickupManager().GetPickups();

	for (auto& bullet : bullets)
	{
		for (auto& enemy : enemies)
		{
			if (bullet->IsOwnedByPlayer() && bullet->DidCollideWithEnemy(*enemy))
			{
				bullet->Destroy();
				enemy->Destroy();
				break;
			}
		}

		if (!bullet->IsOwnedByPlayer() && bullet->DidCollideWithPlayer())
		{
			bullet->Destroy();
			Player::GetInstance().TakeDamage(10);
		}
	}

	for (auto& pickup : pickups)
	{
		if (pickup->DidCollideWithPlayer())
		{
			pickup->Collect();
		}
	}
}