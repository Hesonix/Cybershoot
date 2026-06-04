#pragma once

#include <vector>
#include <memory>
#include "Pickup/Pickup.h"
#include "GameTypes.h"

class PickupManager : public sf::Drawable
{
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	std::vector<std::unique_ptr<Pickup>> pickups;

	void Cleanup();
public:
	void SpawnPickup(PickupType type, sf::Vector2f position);

	void Update(float deltaTime);

	std::vector<std::unique_ptr<Pickup>>& GetPickups() { return pickups; }
};