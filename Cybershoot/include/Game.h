#pragma once

#include "SFML/Graphics.hpp"

#include "RenderManager.h"
#include "ResourceManager.h"
#include "StateManager.h"

class Game
{
private:
	sf::Clock clock;

	RenderManager renderManager;
	ResourceManager resourceManager;
	StateManager stateManager;

	void Initialize();

	void LoadResources();

	void HandleEvents(sf::RenderWindow& window);
	void Update(float deltaTime);
	void Render(sf::RenderWindow& window);
public:
	Game();

	void Run();
};