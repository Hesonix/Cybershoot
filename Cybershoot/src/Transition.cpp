#include "Transition.h"

#include "WindowSettings.h"

Transition::Transition()
{
	overlay.setSize(sf::Vector2f(WindowSettings::WIDTH, WindowSettings::WIDTH));
	overlay.setFillColor(sf::Color::Transparent);
}

Transition& Transition::GetInstance()
{
	static Transition Instance;
	return Instance;
}

void Transition::FadeIn(std::function<void()> onComplete)
{
	isActive = true;
	callback = onComplete;
	isActive = true;
	timer = 0.0f;
	currentType = TransitionType::FadeIn;
	overlay.setFillColor(sf::Color::Transparent);
}

void Transition::FadeInOut(std::function<void()> onComplete)
{
	isActive = true;
	callback = onComplete;
	isActive = true;
	timer = 0.0f;
	currentType = TransitionType::FadeInOut;
	overlay.setFillColor(sf::Color::Transparent);
}

void Transition::UpdateFadeIn(float deltaTime)
{
	timer += deltaTime;
	float fadeInProgress = std::min(1.0f, timer / DURATION);

	sf::Uint8 alpha = static_cast<sf::Uint8>(255.0f * fadeInProgress);

	overlay.setFillColor(sf::Color(0, 0, 0, alpha));

	if (fadeInProgress >= 1.0f)
	{
		isActive = false;
		if (callback)
		{
			callback();
		}
	}
}

void Transition::UpdateFadeInOut(float deltaTime)
{
	timer += deltaTime;
	float fadeInProgress = std::min(1.0f, timer / DURATION);

	if (timer < DURATION)
	{
		sf::Uint8 alpha = static_cast<sf::Uint8>(255.0f * fadeInProgress);
		overlay.setFillColor(sf::Color(0, 0, 0, alpha));
	}
	else if (timer < DURATION * 2)
	{
		if (callback)
		{
			callback();
			callback = nullptr;
		}

		float fadeOutProgress = (timer - DURATION) / DURATION;
		fadeOutProgress = std::min(1.0f, fadeOutProgress);
		sf::Uint8 alpha = static_cast<sf::Uint8>(255.0f * (1.0f - fadeOutProgress));
		overlay.setFillColor(sf::Color(0, 0, 0, alpha));
	}
	else
	{
		isActive = false;
	}
}

void Transition::Update(float deltaTime)
{
	if (!isActive) return;

	switch (currentType)
	{
		case TransitionType::FadeIn:
		{
			UpdateFadeIn(deltaTime);
			break;
		}
		case TransitionType::FadeInOut:
		{
			UpdateFadeInOut(deltaTime);
			break;
		}	
	}
}

void Transition::Render(sf::RenderWindow& window)
{
	if (isActive)
	{
		window.draw(overlay);
	}
}