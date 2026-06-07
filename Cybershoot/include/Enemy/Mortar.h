#pragma once

#include "Enemy.h"

class Mortar : public Enemy
{
private:
	const float ATTACK_RADIUS = 500.0f;
	const float BULLET_SPEED = 1000.0f;
	const float MOVE_SPEED = 200.0f;
	const float ATTACK_COOLDOWN_DURATION = 1.0f;
	const sf::Vector2f BULLET_SPAWN_OFFSET = sf::Vector2f(0.0f, 15.0f);

	float attackCooldown = ATTACK_COOLDOWN_DURATION;

	bool isAttacking = false;
public:
	Mortar(sf::Vector2f position);

	void Attack() override;

	void Update(float deltaTime) override;
};