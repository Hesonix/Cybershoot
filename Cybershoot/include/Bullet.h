#pragma once

#include "SFML/Graphics.hpp"

#include "Enemy/Enemy.h"

#include <memory>

class Bullet : public sf::Drawable
{
private:
	static constexpr float MAX_LIFETIME = 3.0f;

	sf::Sprite sprite;
	sf::Vector2f velocity;
	bool isOwnedByPlayer;

	float lifetime = 0.0f;

	bool isAlive = true;
public:
	Bullet(sf::Vector2f position, sf::Vector2f velocity, bool isOwnedByPlayer);

	sf::Vector2f GetPosition() { return sprite.getPosition(); } 
	sf::FloatRect GetGlobalBounds() { return sprite.getGlobalBounds(); }

	bool IsOwnedByPlayer() { return isOwnedByPlayer; }

	bool DidCollideWithEnemy(Enemy& enemy);
	bool DidCollideWithPlayer();

	bool IsAlive() { return isAlive; }

	void Destroy() { isAlive = false; }

	void Update(float deltaTime);
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};