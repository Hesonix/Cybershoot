#pragma once

#include <vector>

#include "SFML/Graphics.hpp"
#include "GameTypes.h"

class SpawnManager
{
private:
	struct Unlock
	{
		float time;
		EnemyType type;
	};

	std::vector<Unlock> unlocks = {
		{0.0f, EnemyType::Grunt},
		{10.0f, EnemyType::Mortar}
	};

	float spawnTimer = 0.0f;

	std::vector<EnemyType> GetAvailableTypes(float gameTime);
	sf::Vector2f GetRandomEdgePosition();
public:
	void Update(float deltaTime);
};