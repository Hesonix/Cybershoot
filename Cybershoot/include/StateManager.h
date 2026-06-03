#pragma once

#include <memory>
#include <stack>

#include "State.h"

class StateManager
{
private:
	std::stack<std::unique_ptr<State>> states;
public:
	void PushState(std::unique_ptr<State> state);
	void PopState();
	void ChangeState(std::unique_ptr<State> state);

	void HandleInput(sf::Event& event, sf::RenderWindow& window);
	void Update(float deltaTime);
	void Render(sf::RenderWindow& window);
};