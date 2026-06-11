#include "Transition.h"

#include "ManagerLocator.h"
#include "Manager/RenderManager.h"
#include "Manager/StateManager.h"
#include "WindowSettings.h"

Transition::Transition()
{
	overlay.setSize(sf::Vector2f(WindowSettings::WIDTH, WindowSettings::HEIGHT));
	overlay.setFillColor(sf::Color::Transparent);
}

void Transition::StartFadeToState(std::unique_ptr<State> nextState)
{
	type = Type::FadeToState;
	this->nextState = std::move(nextState);
	timer = 0.0f;
	isFadingOut = true;
	isActive = true;
}

void Transition::StartFadeToQuit()
{
	type = Type::FadeToQuit;
	timer = 0.0f;
	isFadingOut = true;
	isActive = true;
}

void Transition::Update(float deltaTime)
{
	timer += deltaTime;

	if (isFadingOut)
	{
		float progress = std::min(1.0f, timer / FADE_OUT_DURATION);

		sf::Uint8 alpha = static_cast<sf::Uint8>(255.0f * progress);

		overlay.setFillColor(sf::Color(0, 0, 0, alpha));

		if (progress >= 1.0f)
		{
			isFadingOut = false;
			timer = 0.0f;

			if (type == Type::FadeToQuit)
			{
				ManagerLocator::GetRenderManager().GetWindow().close();
			}
			else if (type == Type::FadeToState)
			{
				ManagerLocator::GetStateManager().ChangeState(std::move(nextState));
				ManagerLocator::GetRenderManager().GetCamera().SetPosition(sf::Vector2f(0.0f, 0.0f));
			}
		}
	}
	else
	{
		float progress = std::min(1.0f, timer / FADE_IN_DURATION);

		sf::Uint8 alpha = static_cast<sf::Uint8>(255.0f * (1.0f - progress));

		overlay.setFillColor(sf::Color(0, 0, 0, alpha));

		if (progress >= 1.0f)
		{
			isActive = false;
		}
	}
}

void Transition::Render(sf::RenderWindow& window)
{
	window.draw(overlay);
}