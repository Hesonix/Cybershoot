#include "Manager/StateManager.h"

#include "ManagerLocator.h"
#include "Manager/RenderManager.h"
#include "State/MainMenuState.h"

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
	PopState();
	PushState(std::move(state));
}

void StateManager::TransitionTo(std::unique_ptr<State> state)
{
	transition.StartFadeToState(std::move(state));
}

void StateManager::Quit()
{
	transition.StartFadeToQuit();
}

void StateManager::HandleInput(sf::Event& event, sf::RenderWindow& window)
{
	if (!transition.IsActive() && !states.empty())
	{
		states.back()->HandleInput(event, window);
	}
}

void StateManager::Update(float deltaTime)
{
	if (transition.IsActive())
	{
		transition.Update(deltaTime);
	}
	else
	{
		if (!states.empty())
		{
			states.back()->Update(deltaTime);
		}
	}
}

void StateManager::Render(sf::RenderWindow& window)
{
	for (auto& state : states)
	{
		state->Render(window);
	}

	if (transition.IsActive())
	{
		transition.Render(window);
	}
}