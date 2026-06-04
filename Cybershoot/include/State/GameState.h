#pragma once

#include "State.h"
#include "Player.h"
#include "Manager/TileManager.h"
#include "Manager/BulletManager.h"
#include "Manager/EnemyManager.h"
#include "Manager/PickupManager.h"
#include "Manager/CollisionManager.h"
#include "Manager/UIManager.h"
#include "Manager/GameManager.h"
#include "Manager/SpawnManager.h"

class GameState : public State
{
private:	
	Player player;
	TileManager tileManager;
	BulletManager bulletManager;
	EnemyManager enemyManager;
	PickupManager pickupManager;
	CollisionManager collisionManager;
	UIManager uiManager;
	GameManager gameManager;
	SpawnManager spawnManager;

	void Initialize();
public:
	GameState();

	void HandleInput(sf::Event& event, sf::RenderWindow& window) override;
	void Update(float deltaTime) override;
	void Render(sf::RenderWindow& window) override;
};