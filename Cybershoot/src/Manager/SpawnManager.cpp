#include "Manager/SpawnManager.h"

#include "ManagerLocator.h"
#include "Manager/GameManager.h"
#include "RandomGenerator.h"
#include "Manager/EnemyManager.h"
#include "Player.h"

std::vector<EnemyType> SpawnManager::GetAvailableTypes(float gameTime)
{
	std::vector<EnemyType> available;

	for (auto& unlock : unlocks)
	{
		if (gameTime >= unlock.time)
		{
			available.push_back(unlock.type);
		}
	}

	return available;
}

sf::Vector2f SpawnManager::GetRandomEdgePosition()
{
    sf::Vector2f playerPosition = Player::GetInstance().GetPosition();

    int edge = RandomGenerator::GetInt(0, 3);

    float x = 0.0f;
    float y = 0.0f;

    float spawnOffset = 100.0f;

    switch (edge)
    {
    case 0:
        x = playerPosition.x - WindowSettings::CENTER_X - spawnOffset;
        y = playerPosition.y + RandomGenerator::GetFloat(-WindowSettings::CENTER_Y, WindowSettings::CENTER_Y);
        break;

    case 1:
        x = playerPosition.x + WindowSettings::CENTER_X + spawnOffset;
        y = playerPosition.y + RandomGenerator::GetFloat(-WindowSettings::CENTER_Y, WindowSettings::CENTER_Y);
        break;

    case 2:
        x = playerPosition.x + RandomGenerator::GetFloat(-WindowSettings::CENTER_X, WindowSettings::CENTER_X);
        y = playerPosition.y - WindowSettings::CENTER_Y - spawnOffset;
        break;

    case 3:
        x = playerPosition.x + RandomGenerator::GetFloat(-WindowSettings::CENTER_X, WindowSettings::CENTER_X);
        y = playerPosition.y + WindowSettings::CENTER_Y + spawnOffset;
        break;
    }

    return sf::Vector2f(x, y);
}

void SpawnManager::Update(float deltaTime)
{
	spawnTimer += deltaTime;

	float gameTime = ManagerLocator::GetGameManager().GetGameTime();

   	float delay = std::max(0.1f, 1.5f / (1.0f + gameTime / 300.0f));

	if (spawnTimer > delay)
	{
		spawnTimer = 0.0f;

		auto available = GetAvailableTypes(gameTime);

		if (!available.empty())
		{
            int index = RandomGenerator::GetIndex(available);
            ManagerLocator::GetEnemyManager().SpawnEnemy(available[index], GetRandomEdgePosition());
		}
	}
}