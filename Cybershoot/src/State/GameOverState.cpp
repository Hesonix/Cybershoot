#include "State/GameOverState.h"

#include "ManagerLocator.h"
#include "Manager/StateManager.h"
#include "Manager/ResourceManager.h"
#include "WindowSettings.h"
#include "State/MainMenuState.h"

GameOverState::GameOverState()
{
	background.setSize(sf::Vector2f(WindowSettings::WIDTH, WindowSettings::HEIGHT));
	background.setFillColor(sf::Color(0, 0, 0, 150));

	gameOverText.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	gameOverText.SetCharacterSize(50);
	gameOverText.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, WindowSettings::CENTER_Y - 125.0f));
	gameOverText.SetText("GAME OVER");

	quitButton.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	quitButton.SetCharacterSize(50);
	quitButton.SetText("QUIT");
	quitButton.SetSize(sf::Vector2f(400.0f, 150.0f));
	quitButton.SetBackgroundColor(sf::Color(55, 55, 55));
	quitButton.SetOutlineColor(sf::Color::White);
	quitButton.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, WindowSettings::CENTER_Y));
}

void GameOverState::HandleInput(sf::Event& event, sf::RenderWindow& window)
{
	switch (event.type)
	{
		case sf::Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (quitButton.IsHovered())
				{
					ManagerLocator::GetStateManager().PopState();
					ManagerLocator::GetStateManager().ChangeState(std::make_unique<MainMenuState>());
				}
			}
			break;
		}
	}
}

void GameOverState::Update(float deltaTime)
{
	quitButton.Update();
}

void GameOverState::Render(sf::RenderWindow& window)
{
	window.draw(background);
	window.draw(gameOverText);
	window.draw(quitButton);
}