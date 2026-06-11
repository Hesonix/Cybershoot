#pragma once

#include "State/State.h"

class Transition
{
public:
	enum class Type { None, FadeToState, FadeToQuit };

	Transition();

	void StartFadeToState(std::unique_ptr<State> nextState);
	void StartFadeToQuit();

	bool IsActive() { return isActive; }

	void Update(float deltaTime);
	void Render(sf::RenderWindow& window);
private:
	static constexpr float FADE_OUT_DURATION = 0.5f;
	static constexpr float FADE_IN_DURATION = 0.5f;

	Type type = Type::None;
	bool isActive = false;
	bool isFadingOut = true;
	bool stateChanged = false;
	float timer = 0.0f;

	std::unique_ptr<State> nextState;

	sf::RectangleShape overlay;
};