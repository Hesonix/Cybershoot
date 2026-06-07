#pragma once

#include "SFML/Graphics.hpp"

#include "Manager/RenderManager.h"
#include "Manager/ResourceManager.h"
#include "Manager/StateManager.h"
#include "Manager/TileManager.h"

class Game
{
private:
	sf::Clock clock;

	RenderManager renderManager;
	ResourceManager resourceManager;
	StateManager stateManager;
	TileManager tileManager;

	void Initialize();

	void HandleEvents(sf::RenderWindow& window);
	void Update(float deltaTime);
	void Render(sf::RenderWindow& window);
public:
	Game();

	void Run();
};