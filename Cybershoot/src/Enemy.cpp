#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position)
{
	sprite.setOrigin(16.0f, 16.0f);
	sprite.setScale(ENEMY_SCALE, ENEMY_SCALE);
	sprite.setPosition(position);
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite);
}