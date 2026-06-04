#include "Player.h"

#include "ManagerLocator.h"
#include "Manager/RenderManager.h"
#include "Manager/ResourceManager.h"
#include "Manager/UIManager.h"
#include "Weapon/Pistol.h"
#include "Weapon/Shotgun.h"
#include "Weapon/Rifle.h"

Player* Player::Instance = nullptr;

Player::Player()
{
	Instance = this;
	sprite.setOrigin(16.0f, 16.0f);
	sprite.setScale(PLAYER_SCALE, PLAYER_SCALE);
	sprite.setTexture(ManagerLocator::GetResourceManager().GetTextureByName("player"));
}

void Player::TakeDamage(int damage)
{
	health -= damage;
	if (health < 0) health = 0;
	ManagerLocator::GetUIManager().UpdateHealthBar(health);
}

void Player::Heal(int amount)
{
	health += amount;
	if (health > 100) health = 100;
	ManagerLocator::GetUIManager().UpdateHealthBar(health);
}

void Player::SetWeapon(WeaponType type)
{
	switch (type)
	{
		case WeaponType::Pistol: weapon = std::make_unique<Pistol>(); break;
		case WeaponType::Shotgun: weapon = std::make_unique<Shotgun>(); break;
		case WeaponType::Rifle: weapon = std::make_unique<Rifle>(); break;
	}
	ManagerLocator::GetUIManager().UpdateAmmoText(weapon->GetAmmoInMagazine(), weapon->GetTotalReserveAmmo());
}

void Player::Update(float deltaTime)
{
	moveDirection = sf::Vector2f();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) moveDirection.y += -1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) moveDirection.y += 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) moveDirection.x += -1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) moveDirection.x += 1;
	moveDirection = Vector::Normalize(moveDirection);

	sprite.move(moveDirection * moveSpeed * deltaTime);

	sf::Vector2f mouseWorldPosition = ManagerLocator::GetRenderManager().GetMouseWorldPosition();

	lookDirection = Vector::Normalize(mouseWorldPosition - sprite.getPosition());
	lookAngle = atan2(lookDirection.y, lookDirection.x) * 180.0f / 3.14159f;
	
	int direction = lookDirection.x < 0 ? -1 : 1;
	
	sprite.setScale(direction * PLAYER_SCALE, PLAYER_SCALE);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite);
}
