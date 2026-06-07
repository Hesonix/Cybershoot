#include "Manager/StateManager.h"

#include "State/MainMenuState.h"
#include "Transition.h"

void StateManager::Init()
{
	states.push_back(std::make_unique<MainMenuState>());
}

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
	if (Transition::GetInstance().IsActive()) return;

	if (!states.empty())
	{
		states.back()->HandleInput(event, window);
	}
}

void StateManager::Update(float deltaTime)
{
	if (Transition::GetInstance().IsActive()) return;

	if (!states.empty())
	{
		states.back()->Update(deltaTime);
	}
}

void StateManager::Render(sf::RenderWindow& window)
{
	for (auto& state : states)
	{
		state->Render(window);
	}
}