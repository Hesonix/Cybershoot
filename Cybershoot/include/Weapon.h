#pragma once

#include "SFML/Graphics.hpp"

class Weapon : public sf::Drawable
{
protected:
	static constexpr float WEAPON_SCALE = 2.0f;
	static constexpr float RELOAD_TIME = 2.0f;

	const float FIRE_RATE;
	const float BULLET_SPEED;
	const int MAGAZINE_CAPACITY;
	const int STARTING_RESERVE_AMMO;
	const int BULLETS_PER_SHOT;
	const float SPREAD;
	const sf::Vector2f MUZZLE_OFFSET;

	int ammoInMagazine;
	int totalReserveAmmo;

	float timeSinceLastShot = FIRE_RATE;
	float reloadingTime = 0.0f;
	bool isReloading = false;
	bool isFiring = false;

	sf::Sprite sprite;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
	Weapon(float fireRate, float bulletSpeed, int magazineCapacity, int startingReserveAmmo, int bulletsPerShot, float spread, sf::Vector2f muzzleOffset);

	virtual void Fire() = 0;

	void StartFiring() { isFiring = true; }
	void StopFiring() { isFiring = false; }

	void Reload();
	void AddAmmo(int amount);

	bool HasAmmo() { return ammoInMagazine > 0; }

	int GetTotalReserveAmmo() { return totalReserveAmmo; }
	int GetAmmoInMagazine() { return ammoInMagazine; }

	sf::Vector2f GetMuzzlePosition();

	void Update(float deltaTime);
};