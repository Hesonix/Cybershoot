#include "State/PauseState.h"

#include "ManagerLocator.h"
#include "Manager/StateManager.h"
#include "Manager/ResourceManager.h"
#include "WindowSettings.h"
#include "State/MainMenuState.h"

PauseState::PauseState()
{
	background.setSize(sf::Vector2f(800.0f, 500.0f));
	background.setOrigin(400.0f, 250.0f);
	background.setPosition(WindowSettings::CENTER_X, WindowSettings::CENTER_Y);
	background.setFillColor(sf::Color(0, 0, 0, 150));

	pausedText.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	pausedText.SetCharacterSize(50);
	pausedText.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, WindowSettings::CENTER_Y - 225.0f));
	pausedText.SetText("PAUSED");

	resumeButton.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	resumeButton.SetCharacterSize(50);
	resumeButton.SetText("RESUME");
	resumeButton.SetSize(sf::Vector2f(400.0f, 150.0f));
	resumeButton.SetBackgroundColor(sf::Color(55, 55, 55));
	resumeButton.SetOutlineColor(sf::Color::White);
	resumeButton.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, WindowSettings::CENTER_Y - 100.0f));

	quitButton.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	quitButton.SetCharacterSize(50);
	quitButton.SetText("QUIT");
	quitButton.SetSize(sf::Vector2f(400.0f, 150.0f));
	quitButton.SetBackgroundColor(sf::Color(55, 55, 55));
	quitButton.SetOutlineColor(sf::Color::White);
	quitButton.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, WindowSettings::CENTER_Y + 100.0f));
}

void PauseState::HandleInput(sf::Event& event, sf::RenderWindow& window)
{
	switch (event.type)
	{
		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				ManagerLocator::GetStateManager().PopState();
			}
			break;
		}
		case sf::Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (resumeButton.IsHovered())
				{
					ManagerLocator::GetStateManager().PopState();
				}
				else if (quitButton.IsHovered())
				{
					ManagerLocator::GetStateManager().PopState();
					ManagerLocator::GetStateManager().ChangeState(std::make_unique<MainMenuState>());
				}
			}
			break;
		}
	}
}

void PauseState::Update(float deltaTime)
{
	resumeButton.Update();
	quitButton.Update();
}

void PauseState::Render(sf::RenderWindow& window)
{
	window.draw(background);
	window.draw(pausedText);
	window.draw(resumeButton);
	window.draw(quitButton);
}