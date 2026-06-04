#include "Weapon/Pistol.h"

#include "ManagerLocator.h"
#include "Manager/ResourceManager.h"
#include "Manager/BulletManager.h"
#include "Player.h"

void Pistol::Fire()
{
	if (isReloading || ammoInMagazine <= 0) return;

	sf::Vector2f playerLookDirection = Player::GetInstance().GetLookDirection();
	
	ManagerLocator::GetBulletManager().SpawnBullet(
		GetMuzzlePosition(),
		playerLookDirection * BULLET_SPEED,
		true
	);

	ammoInMagazine--;
}

Pistol::Pistol()
	: Weapon(0.5f, 2000.0f, 6, 24, 1, 0.05f, sf::Vector2f(0.0f, 0.0f))
{
	sprite.setOrigin(16.0f, 16.0f);
	sprite.setScale(WEAPON_SCALE, WEAPON_SCALE);
	sprite.setTexture(ManagerLocator::GetResourceManager().GetTextureByName("pistol"));
}