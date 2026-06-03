#pragma once

#include "SFML/Graphics.hpp"

class Enemy : public sf::Drawable
{
protected:
	const float ENEMY_SCALE = 2.0f;

	Enemy(sf::Vector2f position);

	sf::Sprite sprite;

	bool isAlive = true;

	virtual void Attack() = 0;
public:
	sf::Vector2f GetPosition() { return sprite.getPosition(); }
	sf::FloatRect GetGlobalBounds() { return sprite.getGlobalBounds(); };

	bool IsAlive() { return isAlive; }

	void Destroy() { isAlive = false; }

	virtual void Update(float deltaTime) = 0;
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};