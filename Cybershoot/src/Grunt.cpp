#include "Grunt.h"

#include "ManagerLocator.h"
#include "ResourceManager.h"
#include "Player.h"
#include "Vector.h"

Grunt::Grunt(sf::Vector2f position)
	: Enemy(position)
{
	sprite.setTexture(ManagerLocator::GetResourceManager().GetTextureByName("grunt"));
}

void Grunt::Attack()
{
	Player::GetInstance().TakeDamage(10);
}

void Grunt::Update(float deltaTime)
{
	sf::Vector2f playerPosition = Player::GetInstance().GetPosition();
	sf::Vector2f enemyPosition = sprite.getPosition();

	float distanceToPlayer = Vector::Distance(playerPosition, enemyPosition);

	if (!isAttacking && distanceToPlayer <= ATTACK_RADIUS)
	{
		isAttacking = true;
	}

	if (isAttacking)
	{
		attackCooldown -= deltaTime;
		if (attackCooldown < 0)
		{
			if (distanceToPlayer < ATTACK_RADIUS)
			{
				Attack();
			}

			isAttacking = false;
			attackCooldown = ATTACK_COOLDOWN_DURATION;
			return;
		}
		else
		{
			return;
		}
	}

	sf::Vector2f moveDirection = Vector::Normalize(playerPosition - enemyPosition);
	sprite.move(moveDirection * MOVE_SPEED * deltaTime);
}