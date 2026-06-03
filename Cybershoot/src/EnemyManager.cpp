#include "EnemyManager.h"
#include "Grunt.h"
#include "Mortar.h"

void EnemyManager::SpawnEnemy(EnemyType type, sf::Vector2f position)
{
	switch (type)
	{
		case EnemyType::Grunt: enemies.push_back(std::make_unique<Grunt>(position)); break;
		case EnemyType::Mortar: enemies.push_back(std::make_unique<Mortar>(position)); break;
	}
}

std::vector<std::unique_ptr<Enemy>>& EnemyManager::GetEnemies()
{
	return enemies;
}

void EnemyManager::Cleanup()
{
	enemies.erase(
		std::remove_if(enemies.begin(), enemies.end(),
			[](auto& enemy) { return !enemy->IsAlive(); }),
		enemies.end()
	);
}

void EnemyManager::Update(float deltaTime)
{
	Cleanup();

	for (auto& enemy : enemies)
	{
		enemy->Update(deltaTime);
	}
}

void EnemyManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const auto& enemy : enemies)
	{
		target.draw(*enemy);
	}
}