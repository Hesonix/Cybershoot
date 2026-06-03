#pragma once
#include <vector>
#include "Bullet.h"
#include "Enemy.h"

#include <memory>

class BulletManager : public sf::Drawable
{
private:
	std::vector<std::unique_ptr<Bullet>> bullets;
public:
	void SpawnBullet(sf::Vector2f position, sf::Vector2f velocity, bool isOwnedByPlayer);

	std::vector<std::unique_ptr<Bullet>>& GetBullets();

	void Cleanup();
	
	void Update(float deltaTime);
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};