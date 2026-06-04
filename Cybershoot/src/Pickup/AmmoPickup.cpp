#include "Pickup/AmmoPickup.h"
#include "Player.h"
#include "ManagerLocator.h"
#include "Manager/ResourceManager.h"

AmmoPickup::AmmoPickup(sf::Vector2f position)
	: Pickup(position)
{
	sprite.setTexture(ManagerLocator::GetResourceManager().GetTextureByName("ammo_pickup"));
}

void AmmoPickup::Collect()
{
	Player::GetInstance().GetWeapon().AddAmmo(ADD_AMMO_AMOUNT);
	Destroy();
}
