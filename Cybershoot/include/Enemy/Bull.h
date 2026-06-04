#pragma once

#include "Enemy.h"

class Bull : public Enemy
{
private:
	const float ATTACK_RADIUS = 500.0f;
	const float ATTACK_COOLDOWN = 0.5f;
	const float MOVE_SPEED = 200.0f;
	const float DASH_PREPARE_TIME = 1.0f;
	const float DASH_DURATION = 1.0f;
	const float DASH_SPEED = 1000.0f;

	sf::Vector2f dashDirection;
	bool isAttacking = false;
	bool isDashing = false;
	bool canDamage = true;
	float prepareTimer = 0.0f;
	float dashTimer = 0.0f;
	float attackCooldown = 0.0f;

	bool DidCollideWithPlayer();
public:
	Bull(sf::Vector2f position);

	void Attack() override;

	void Update(float deltaTime) override;
};