#include "Manager/SpawnManager.h"

#include "Player.h"
#include "ManagerLocator.h"
#include "Manager/GameManager.h"
#include "Manager/RenderManager.h"
#include "Manager/EnemyManager.h"
#include "Manager/PickupManager.h""
#include "RandomGenerator.h"

std::vector<EnemyType> SpawnManager::GetAvailableEnemyTypes(float gameTime)
{
	std::vector<EnemyType> available;

	for (auto& enemyUnlock : enemyUnlocks)
	{
		if (gameTime >= enemyUnlock.time)
		{
			available.push_back(enemyUnlock.type);
		}
	}

	return available;
}

sf::Vector2f SpawnManager::GetRandomEdgePosition()
{
    sf::Vector2f cameraPosition = ManagerLocator::GetRenderManager().GetCamera().GetPosition();

    int edge = RandomGenerator::GetInt(0, 3);

    float x = 0.0f;
    float y = 0.0f;

    switch (edge)
    {
    case 0:
        x = cameraPosition.x - WindowSettings::CENTER_X - SPAWN_EDGE_OFFSET;
        y = cameraPosition.y + RandomGenerator::GetFloat(-WindowSettings::CENTER_Y, WindowSettings::CENTER_Y);
        break;

    case 1:
        x = cameraPosition.x + WindowSettings::CENTER_X + SPAWN_EDGE_OFFSET;
        y = cameraPosition.y + RandomGenerator::GetFloat(-WindowSettings::CENTER_Y, WindowSettings::CENTER_Y);
        break;

    case 2:
        x = cameraPosition.x + RandomGenerator::GetFloat(-WindowSettings::CENTER_X, WindowSettings::CENTER_X);
        y = cameraPosition.y - WindowSettings::CENTER_Y - SPAWN_EDGE_OFFSET;
        break;

    case 3:
        x = cameraPosition.x + RandomGenerator::GetFloat(-WindowSettings::CENTER_X, WindowSettings::CENTER_X);
        y = cameraPosition.y + WindowSettings::CENTER_Y + SPAWN_EDGE_OFFSET;
        break;
    }

    return sf::Vector2f(x, y);
}

void SpawnManager::Update(float deltaTime)
{
	enemySpawnTimer += deltaTime;
    pickupSpawnTimer += deltaTime;

	float gameTime = ManagerLocator::GetGameManager().GetGameTime();

   	float enemySpawnDelay = std::max(0.1f, 1.5f / (1.0f + gameTime / 300.0f));

    float pickupSpawnDelay = 10.0f;

	if (enemySpawnTimer >= enemySpawnDelay)
	{
        enemySpawnTimer = 0.0f;

		auto available = GetAvailableEnemyTypes(gameTime);

		if (!available.empty())
		{
            int index = RandomGenerator::GetIndex(available);
            ManagerLocator::GetEnemyManager().SpawnEnemy(available[index], GetRandomEdgePosition());
		}
	}

    if (pickupSpawnTimer >= pickupSpawnDelay)
    {
        pickupSpawnTimer = 0.0f;

        PickupType randomType = RandomGenerator::GetFloat(0, 100) <= 70 ? PickupType::Ammo : PickupType::Health;

        ManagerLocator::GetPickupManager().SpawnPickup(randomType, GetRandomEdgePosition());
    }
}