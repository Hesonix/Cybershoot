#include "Weapon/Weapon.h"

#include "ManagerLocator.h"
#include "Manager/UIManager.h"
#include "Player.h"

sf::Vector2f Weapon::GetMuzzlePosition()
{
	float angleRad = sprite.getRotation() * 3.14159f / 180.0f;

	sf::Vector2f muzzleOffsetWorld;
	if (sprite.getRotation() > 90 && sprite.getRotation() < 270)
	{
		muzzleOffsetWorld.x = MUZZLE_OFFSET.x * cos(angleRad) + MUZZLE_OFFSET.y * sin(angleRad);
		muzzleOffsetWorld.y = MUZZLE_OFFSET.x * sin(angleRad) - MUZZLE_OFFSET.y * cos(angleRad);
	}
	else
	{
		muzzleOffsetWorld.x = MUZZLE_OFFSET.x * cos(angleRad) - MUZZLE_OFFSET.y * sin(angleRad);
		muzzleOffsetWorld.y = MUZZLE_OFFSET.x * sin(angleRad) + MUZZLE_OFFSET.y * cos(angleRad);
	}
	
	return sprite.getPosition() + muzzleOffsetWorld;
}

void Weapon::Reload()
{
	if (isReloading || ammoInMagazine == MAGAZINE_CAPACITY || totalReserveAmmo == 0) return;

	isReloading = true;

	ManagerLocator::GetUIManager().UpdateReloadingText(true);

	int bulletsNeeded = MAGAZINE_CAPACITY - ammoInMagazine;

	if (totalReserveAmmo >= bulletsNeeded)
	{
		totalReserveAmmo -= bulletsNeeded;
		ammoInMagazine += bulletsNeeded;
	}
	else
	{
		ammoInMagazine += totalReserveAmmo;
		totalReserveAmmo = 0;
	}
}

void Weapon::AddAmmo(int amount)
{
	totalReserveAmmo += amount;
	ManagerLocator::GetUIManager().UpdateAmmoText(ammoInMagazine, totalReserveAmmo);
}

void Weapon::Update(float deltaTime)
{
	timeSinceLastShot += deltaTime;
	
	if (isReloading)
	{
		reloadingTime += deltaTime;
	}
	
	if (reloadingTime > RELOAD_TIME)
	{
		isReloading = false;
		reloadingTime = 0.0f;
		ManagerLocator::GetUIManager().UpdateReloadingText(false);
		ManagerLocator::GetUIManager().UpdateAmmoText(ammoInMagazine, totalReserveAmmo);
	}

	if (isFiring && timeSinceLastShot > FIRE_RATE && !isReloading)
	{
		Fire();
		ManagerLocator::GetUIManager().UpdateAmmoText(ammoInMagazine, totalReserveAmmo);
		timeSinceLastShot = 0.0f;
		if (ammoInMagazine == 0) Reload();
	}

	sf::Vector2f playerPosition = Player::GetInstance().GetPosition();
	sf::Vector2f playerLookDirection = Player::GetInstance().GetLookDirection();
	float playerLookAngle = Player::GetInstance().GetLookAngle();
	
	sprite.setPosition(playerPosition + playerLookDirection * Player::WEAPON_OFFSET);
	sprite.setRotation(playerLookAngle);
	
	int direction = playerLookDirection.x < 0 ? -1 : 1;
	
	sprite.setScale(WEAPON_SCALE, direction * WEAPON_SCALE);
}

void Weapon::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite);
}

Weapon::Weapon(float fireRate, float bulletSpeed, int magazineCapacity, int startingReserveAmmo, int bulletsPerShot, float spread, sf::Vector2f muzzleOffset)
	: FIRE_RATE(fireRate)
	, BULLET_SPEED(bulletSpeed)
	, MAGAZINE_CAPACITY(magazineCapacity)
	, STARTING_RESERVE_AMMO(startingReserveAmmo)
	, BULLETS_PER_SHOT(bulletsPerShot)
	, SPREAD(spread)
	, MUZZLE_OFFSET(muzzleOffset)
	, ammoInMagazine(magazineCapacity)
	, totalReserveAmmo(startingReserveAmmo)
{

}