#pragma once

#include "State.h"
#include "Player.h"
#include "TileManager.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "PickupManager.h"
#include "CollisionManager.h"
#include "UIManager.h"
#include "GameManager.h"
#include "SpawnManager.h"

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