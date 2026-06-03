#include "StateManager.h"

void StateManager::PushState(std::unique_ptr<State> state)
{
	states.push(std::move(state));
}

void StateManager::PopState()
{
	if (!states.empty())
	{
		states.pop();
	}
}

void StateManager::ChangeState(std::unique_ptr<State> state)
{
	if (!states.empty())
	{
		states.pop();
	}
	states.push(std::move(state));
}

void StateManager::HandleInput(sf::Event& event, sf::RenderWindow& window)
{
	if (!states.empty())
	{
		states.top()->HandleInput(event, window);
	}
}

void StateManager::Update(float deltaTime)
{
	if (!states.empty())
	{
		states.top()->Update(deltaTime);
	}
}

void StateManager::Render(sf::RenderWindow& window)
{
	if (!states.empty())
	{
		states.top()->Render(window);
	}
}