#pragma once

#include <vector>

#include "SFML/Graphics.hpp"
#include "GameTypes.h"

class SpawnManager
{
private:
	static constexpr float SPAWN_EDGE_OFFSET = 100.0f;

	struct EnemyUnlock
	{
		float time;
		EnemyType type;
	};

	std::vector<EnemyUnlock> enemyUnlocks = {
		{0.0f, EnemyType::Grunt},
		{150.0f, EnemyType::Mortar},
		{300.0f, EnemyType::Bull}
	};

	float enemySpawnTimer = 0.0f;
	float pickupSpawnTimer = 0.0f;

	std::vector<EnemyType> GetAvailableEnemyTypes(float gameTime);
	sf::Vector2f GetRandomEdgePosition();
public:
	void Update(float deltaTime);
};