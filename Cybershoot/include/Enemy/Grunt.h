#pragma once

#include "Enemy.h"

class Grunt : public Enemy
{
private:
	const float ATTACK_RADIUS = 90.0f;
	const float ATTACK_COOLDOWN_DURATION = 1.0f;
	const float MOVE_SPEED = 200.0f;

	bool isAttacking = false;

	float attackCooldown = ATTACK_COOLDOWN_DURATION;
public:
	Grunt(sf::Vector2f position);

	void Attack() override;

	void Update(float deltaTime) override;
};