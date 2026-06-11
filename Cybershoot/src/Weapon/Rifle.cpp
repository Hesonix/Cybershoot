#include "Weapon/Rifle.h"

#include "ManagerLocator.h"
#include "Manager/ResourceManager.h"
#include "Manager/BulletManager.h"
#include "Player.h"

Rifle::Rifle()
	: Weapon(0.1f, 2000.0f, 30, 90, 1, 0.05f, sf::Vector2f(0.0f, 0.0f))
{
	sprite.setOrigin(16.0f, 16.0f);
	sprite.setScale(WEAPON_SCALE, WEAPON_SCALE);
	sprite.setTexture(ManagerLocator::GetResourceManager().GetTextureByName("pistol"));
}