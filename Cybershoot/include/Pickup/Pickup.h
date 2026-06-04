#pragma once

#include "SFML/Graphics.hpp"

class Pickup : public sf::Drawable
{
protected:
	Pickup(sf::Vector2f position);

	sf::Sprite sprite;

	bool isAlive = true;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
	virtual void Collect() = 0;

	bool DidCollideWithPlayer();

	void Destroy() { isAlive = false; }

	bool IsAlive() { return isAlive; }

	sf::FloatRect GetGlobalBounds() { return sprite.getGlobalBounds(); }
};