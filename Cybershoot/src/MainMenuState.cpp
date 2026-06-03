#include "MainMenuState.h"

#include "ManagerLocator.h"
#include "ResourceManager.h"
#include "StateManager.h"
#include "GameState.h"
#include "WindowSettings.h"

MainMenuState::MainMenuState()
{
	titleText.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	titleText.SetCharacterSize(100);
	titleText.SetText("CYBERSHOOT");
	titleText.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, 100.0f));

	playButton.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	playButton.SetCharacterSize(50);
	playButton.SetText("PLAY");
	playButton.SetSize(sf::Vector2f(400.0f, 150.0f));
	playButton.SetBackgroundColor(sf::Color(55, 55, 55));
	playButton.SetOutlineColor(sf::Color::White);
	playButton.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, 500.0f));

	quitButton.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	quitButton.SetCharacterSize(50);
	quitButton.SetText("QUIT");
	quitButton.SetSize(sf::Vector2f(400.0f, 150.0f));
	quitButton.SetBackgroundColor(sf::Color(55, 55, 55));
	quitButton.SetOutlineColor(sf::Color::White);
	quitButton.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, 800.0f));
}

void MainMenuState::HandleInput(sf::Event& event, sf::RenderWindow& window)
{
	switch (event.type)
	{
		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
			break;
		}
		case sf::Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (playButton.IsHovered())
				{
					ManagerLocator::GetStateManager().ChangeState(std::make_unique<GameState>());
				}
				else if (quitButton.IsHovered())
				{
					window.close();
				}
			}
			break;
		}
	}
}

void MainMenuState::Update(float deltaTime)
{
	playButton.Update();
	quitButton.Update();
}

void MainMenuState::Render(sf::RenderWindow& window)
{
	window.draw(titleText);
	window.draw(playButton);
	window.draw(quitButton);
}