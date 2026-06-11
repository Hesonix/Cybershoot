#pragma once

#include <memory>
#include <vector>

#include "State/State.h"
#include "Transition.h"

class StateManager
{
private:
	std::vector<std::unique_ptr<State>> states;

	Transition transition;
public:
	void PushState(std::unique_ptr<State> state);
	void PopState();
	void ChangeState(std::unique_ptr<State> state);
	void TransitionTo(std::unique_ptr<State> state);
	void Quit();

	void HandleInput(sf::Event& event, sf::RenderWindow& window);
	void Update(float deltaTime);
	void Render(sf::RenderWindow& window);
};