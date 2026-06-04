#pragma once

#include "Pickup.h"

class HealthPickup : public Pickup
{
private:
	const int ADD_HEALTH_AMOUNT = 10;
public:
	HealthPickup(sf::Vector2f position);

	void Collect() override;
};