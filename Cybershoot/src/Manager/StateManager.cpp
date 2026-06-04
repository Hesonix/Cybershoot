#include "Manager/StateManager.h"

void StateManager::PushState(std::unique_ptr<State> state)
{
	states.push_back(std::move(state));
}

void StateManager::PopState()
{
	if (!states.empty())
	{
		states.pop_back();
	}
}

void StateManager::ChangeState(std::unique_ptr<State> state)
{
	if (!states.empty())
	{
		states.pop_back();
	}
	states.push_back(std::move(state));
}

void StateManager::HandleInput(sf::Event& event, sf::RenderWindow& window)
{
	if (!states.empty())
	{
		states.back()->HandleInput(event, window);
	}
}

void StateManager::Update(float deltaTime)
{
	if (!states.empty())
	{
		states.back()->Update(deltaTime);
	}
}

void StateManager::Render(sf::RenderWindow& window)
{
	if (!states.empty())
	{
		for (auto& state : states)
		{
			state->Render(window);
		}
	}
}