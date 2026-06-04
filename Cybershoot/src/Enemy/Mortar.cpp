#include "Enemy/Mortar.h"

#include "ManagerLocator.h"
#include "Manager/ResourceManager.h"
#include "Player.h"
#include "Util/Vector.h"
#include "Manager/BulletManager.h"

Mortar::Mortar(sf::Vector2f position)
	: Enemy(position)
{
	sprite.setTexture(ManagerLocator::GetResourceManager().GetTextureByName("mortar"));
}

void Mortar::Attack()
{
	sf::Vector2f playerPosition = Player::GetInstance().GetPosition();

	sf::Vector2f directionToPlayer = Vector::Normalize(playerPosition - GetPosition());

	ManagerLocator::GetBulletManager().SpawnBullet(GetPosition() + BULLET_SPAWN_OFFSET, directionToPlayer * BULLET_SPEED, false);
}

void Mortar::Update(float deltaTime)
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
			Attack();
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