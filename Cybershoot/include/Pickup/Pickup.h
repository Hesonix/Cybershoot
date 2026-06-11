#pragma once

#include "SFML/Graphics.hpp"

class Pickup : public sf::Drawable
{
protected:
	static constexpr float MAX_LIFETIME = 10.0f;
	static constexpr float BLINK_START_TIME = 7.0f;
	static constexpr float BLINK_INTERVAL = 0.2f;

	Pickup(sf::Vector2f position);

	sf::Sprite sprite;

	float lifetime = 0.0f;
	
	float blinkTimer = 0.0f;

	bool isAlive = true;

	bool isVisible = true;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
	virtual void Collect() = 0;

	bool DidCollideWithPlayer();

	void Update(float deltaTime);

	void Destroy() { isAlive = false; }

	bool IsAlive() { return isAlive; }

	sf::FloatRect GetGlobalBounds() { return sprite.getGlobalBounds(); }
};