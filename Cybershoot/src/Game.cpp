#include "Game.h"

#include <iostream>
#include "ManagerLocator.h"
#include "State/MainMenuState.h"

Game::Game()
{
	Initialize();

	LoadResources();

	stateManager.PushState(std::make_unique<MainMenuState>());
}

void Game::Initialize()
{
	ManagerLocator::SetRenderManager(&renderManager);
	ManagerLocator::SetResourceManager(&resourceManager);
	ManagerLocator::SetStateManager(&stateManager);
}

void Game::LoadResources()
{
	resourceManager.LoadFont("UI", "res/fonts/Tiny5-Regular.ttf");
	resourceManager.LoadTexture("floor", "res/textures/floor.png");
	resourceManager.LoadTexture("player", "res/textures/player.png");
	resourceManager.LoadTexture("pistol", "res/textures/pistol.png");
	resourceManager.LoadTexture("bullet", "res/textures/bullet.png");
	resourceManager.LoadTexture("grunt", "res/textures/grunt.png");
	resourceManager.LoadTexture("mortar", "res/textures/mortar.png");
	resourceManager.LoadTexture("bull", "res/textures/bull.png");
	resourceManager.LoadTexture("ammo_pickup", "res/textures/ammo_pickup.png");
	resourceManager.LoadTexture("health_pickup", "res/textures/health_pickup.png");
}

void Game::HandleEvents(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}

		stateManager.HandleInput(event, window);
	}
}

void Game::Update(float deltaTime)
{
	stateManager.Update(deltaTime);
}

void Game::Render(sf::RenderWindow& window)
{
	window.clear();
	stateManager.Render(window);
	window.display();
}

void Game::Run()
{
	sf::RenderWindow& window = ManagerLocator::GetRenderManager().GetWindow();

	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();

		HandleEvents(window);
		Update(deltaTime);
		Render(window);
	}
}