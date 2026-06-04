#pragma once

#include "SFML/Graphics.hpp"
#include <vector>
#include "Enemy/Enemy.h"
#include <memory>
#include "GameTypes.h"

class EnemyManager : public sf::Drawable
{
private:
	std::vector<std::unique_ptr<Enemy>> enemies;
public:
	void SpawnEnemy(EnemyType type, sf::Vector2f position);

	std::vector<std::unique_ptr<Enemy>>& GetEnemies();

	void Cleanup();

	void Update(float deltaTime);
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
