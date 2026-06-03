#pragma once

#include "Pickup.h"

class AmmoPickup : public Pickup
{
private:
	static constexpr int ADD_AMMO_AMOUNT = 16;
public:
	AmmoPickup(sf::Vector2f position);

	void Collect() override;
};