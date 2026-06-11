#include "Weapon/Shotgun.h"

#include "ManagerLocator.h"
#include "Manager/ResourceManager.h"
#include "Manager/BulletManager.h"
#include "Player.h"
#include "RandomGenerator.h"

void Shotgun::Fire()
{
	if (isReloading || ammoInMagazine <= 0) return;

	sf::Vector2f playerLookDirection = Player::GetInstance().GetLookDirection();

	ManagerLocator::GetBulletManager().SpawnBullet(
		GetMuzzlePosition(),
		playerLookDirection * BULLET_SPEED,
		true
	);

	ManagerLocator::GetBulletManager().SpawnBullet(
		GetMuzzlePosition(),
		Vector::Rotate(playerLookDirection, -SPREAD) * BULLET_SPEED,
		true
	);

	ManagerLocator::GetBulletManager().SpawnBullet(
		GetMuzzlePosition(),
		Vector::Rotate(playerLookDirection, SPREAD) * BULLET_SPEED,
		true
	);

	ammoInMagazine--;
}

Shotgun::Shotgun()
	: Weapon(0.5f, 2000.0f, 6, 24, 5, 0.25f, sf::Vector2f(0.0f, 0.0f))
{
	sprite.setOrigin(16.0f, 16.0f);
	sprite.setScale(WEAPON_SCALE, WEAPON_SCALE);
	sprite.setTexture(ManagerLocator::GetResourceManager().GetTextureByName("shotgun"));
}