#include "Game.h"

#include "ManagerLocator.h"
#include "State/MainMenuState.h"

Game::Game()
{
	Initialize();

	stateManager.PushState(std::make_unique<MainMenuState>());
}

void Game::Initialize()
{
	ManagerLocator::SetRenderManager(&renderManager);
	ManagerLocator::SetResourceManager(&resourceManager);
	ManagerLocator::SetStateManager(&stateManager);
	ManagerLocator::SetScoreManager(&scoreManager);
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
	sf::RenderWindow& window = renderManager.GetWindow();

	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();

		HandleEvents(window);
		Update(deltaTime);
		Render(window);
	}
}