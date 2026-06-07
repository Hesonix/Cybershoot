#pragma once

#include "SFML/Graphics.hpp"
#include <functional>

enum class TransitionType
{
	None,
	FadeIn,
	FadeInOut
};

class Transition
{
private:
	static constexpr float DURATION = 0.5f;

	bool isActive = false;
	TransitionType currentType = TransitionType::None;
	std::function<void()> callback;
	float timer = 0.0f;

	sf::RectangleShape overlay;
public:
	Transition();

	static Transition& GetInstance();

	bool IsActive() { return isActive; }
	
	void FadeIn(std::function<void()> onComplete = nullptr);
	void FadeInOut(std::function<void()> onComplete = nullptr);

	void UpdateFadeIn(float deltaTime);
	void UpdateFadeInOut(float deltaTime);

	void Update(float deltaTime);
	void Render(sf::RenderWindow& window);
};