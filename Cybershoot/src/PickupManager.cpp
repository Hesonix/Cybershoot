#include "PickupManager.h"

#include "AmmoPickup.h"
#include "HealthPickup.h"

void PickupManager::SpawnPickup(PickupType type, sf::Vector2f position)
{
	switch (type)
	{
		case PickupType::Ammo: pickups.push_back(std::make_unique<AmmoPickup>(position)); break;
		case PickupType::Health: pickups.push_back(std::make_unique<HealthPickup>(position)); break;
	}
}

void PickupManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& pickup : pickups)
	{
		target.draw(*pickup);
	}
}

void PickupManager::Cleanup()
{
	pickups.erase(
		std::remove_if(pickups.begin(), pickups.end(),
			[](auto& pickup) { return !pickup->IsAlive(); }),
		pickups.end()
	);
}

void PickupManager::Update()
{
	Cleanup();
}
