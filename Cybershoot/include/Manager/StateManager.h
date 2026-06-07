#pragma once

#include <memory>
#include <vector>

#include "State/State.h"

class StateManager
{
private:
	std::vector<std::unique_ptr<State>> states;
public:
	void Init();

	void PushState(std::unique_ptr<State> state);
	void PopState();
	void ChangeState(std::unique_ptr<State> state);

	void HandleInput(sf::Event& event, sf::RenderWindow& window);
	void Update(float deltaTime);
	void Render(sf::RenderWindow& window);
};