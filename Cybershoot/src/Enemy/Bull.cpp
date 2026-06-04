#include "Enemy/Bull.h"

#include "Player.h"
#include "ManagerLocator.h"
#include "Manager/ResourceManager.h"
#include "Util/Vector.h"
#include "Collision.h"

Bull::Bull(sf::Vector2f position)
	: Enemy(position)
{
	sprite.setTexture(ManagerLocator::GetResourceManager().GetTextureByName("bull"));
}

bool Bull::DidCollideWithPlayer()
{
	return Collision::CheckRectangleCollision(GetGlobalBounds(), Player::GetInstance().GetGlobalBounds());
}

void Bull::Attack()
{
	Player::GetInstance().TakeDamage(10);
}

void Bull::Update(float deltaTime)
{
	if (attackCooldown > 0)
	{
		attackCooldown -= deltaTime;
		return;
	}

	sf::Vector2f playerPosition = Player::GetInstance().GetPosition();
	sf::Vector2f enemyPosition = sprite.getPosition();

	float distanceToPlayer = Vector::Distance(playerPosition, enemyPosition);

	if (distanceToPlayer <= ATTACK_RADIUS && !isAttacking)
	{
		isAttacking = true;
	}

	if (isAttacking)
	{
		if (!isDashing)
		{
			prepareTimer += deltaTime;

			if (prepareTimer >= DASH_PREPARE_TIME)
			{
				isDashing = true;
			}
		}

		if (isDashing)
		{
			if (dashDirection == sf::Vector2f(0.0f, 0.0f))
			{
				dashDirection = Vector::Normalize(playerPosition - enemyPosition);
			}

			dashTimer += deltaTime;

			if (canDamage && DidCollideWithPlayer())
			{
				Player::GetInstance().TakeDamage(10);
				canDamage = false;
			}

			if (dashTimer >= DASH_DURATION)
			{
				isDashing = false;
				isAttacking = false;
				canDamage = true;
				attackCooldown = ATTACK_COOLDOWN;
				prepareTimer = 0.0f;
				dashTimer = 0.0f;
				dashDirection = sf::Vector2f(0.0f, 0.0f);
			}
			else
			{
				sprite.move(dashDirection * DASH_SPEED * deltaTime);
			}
		}
		return;
	}

	sf::Vector2f moveDirection = Vector::Normalize(playerPosition - enemyPosition);
	sprite.move(moveDirection * MOVE_SPEED * deltaTime);
}