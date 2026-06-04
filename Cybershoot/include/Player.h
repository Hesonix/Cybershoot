#pragma once
#include <memory>
#include "SFML/Graphics.hpp"
#include "Util/Vector.h"
#include "Weapon/Weapon.h"
#include "ManagerLocator.h"
#include "Manager/UIManager.h"
#include "GameTypes.h"

class Player : public sf::Drawable
{
private:
	static constexpr float PLAYER_SCALE = 2.0f;

	static Player* Instance;

	std::unique_ptr<Weapon> weapon = nullptr;

	sf::Sprite sprite;
	
	sf::Vector2f moveDirection;
	sf::Vector2f lookDirection;
	float lookAngle = 0.0f;
	
	float moveSpeed = 300.0f;
	int health = 100;
public:
	static constexpr float WEAPON_OFFSET = 50.0f;

	Player();

	static Player& GetInstance() { return *Instance; }

	sf::Vector2f GetPosition() { return sprite.getPosition(); }
	sf::Vector2f GetLookDirection() { return lookDirection; }

	float GetLookAngle() { return lookAngle; }

	sf::FloatRect GetGlobalBounds() { return sprite.getGlobalBounds(); }
	
	Weapon& GetWeapon() { return *weapon.get(); }

	int GetHealth() { return health; }

	bool IsAlive() { return health > 0; }
	bool HasWeapon() { return weapon != nullptr; }

	void TakeDamage(int damage);
	void Heal(int amount);
	void SetWeapon(WeaponType type);

	void Update(float deltaTime);
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};