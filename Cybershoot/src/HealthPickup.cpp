#include "HealthPickup.h"

#include "ManagerLocator.h"
#include "Player.h"
#include "ResourceManager.h"

HealthPickup::HealthPickup(sf::Vector2f position)
	: Pickup(position)
{
	sprite.setTexture(ManagerLocator::GetResourceManager().GetTextureByName("health_pickup"));
}

void HealthPickup::Collect()
{
	Player::GetInstance().Heal(ADD_HEALTH_AMOUNT);
	Destroy();
}