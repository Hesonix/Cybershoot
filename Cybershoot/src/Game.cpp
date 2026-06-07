#include "Game.h"

#include <iostream>
#include "ManagerLocator.h"
#include "State/MainMenuState.h"
#include "Transition.h"

Game::Game()
{
	Initialize();
}

void Game::Initialize()
{
	ManagerLocator::SetRenderManager(&renderManager);
	ManagerLocator::SetResourceManager(&resourceManager);
	ManagerLocator::SetTileManager(&tileManager);
	ManagerLocator::SetStateManager(&stateManager);
	
	renderManager.Init();
	resourceManager.Init();
	tileManager.Init();
	stateManager.Init();	
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
	Transition::GetInstance().Update(deltaTime);
	stateManager.Update(deltaTime);
}

void Game::Render(sf::RenderWindow& window)
{
	window.clear();
	stateManager.Render(window);
	Transition::GetInstance().Render(window);
	window.display();
}

void Game::Run()
{
	sf::RenderWindow& window = renderManager.GetWindow();

	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();

		HandleEvents(window);
		Update(deltaTime);
		Render(window);
	}
}