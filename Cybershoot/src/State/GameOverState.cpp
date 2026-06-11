#include "State/GameOverState.h"

#include "ManagerLocator.h"
#include "Manager/StateManager.h"
#include "Manager/ResourceManager.h"
#include "State/MainMenuState.h"
#include "WindowSettings.h"

GameOverState::GameOverState()
{
	Initialize();
}

void GameOverState::Initialize()
{
	background.setSize(sf::Vector2f(WindowSettings::WIDTH, WindowSettings::HEIGHT));
	background.setFillColor(sf::Color(0, 0, 0, 150));

	gameOverText.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	gameOverText.SetCharacterSize(100);
	gameOverText.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, 100.0f));
	gameOverText.SetText("GAME OVER");

	scoreText.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	scoreText.SetCharacterSize(100);
	scoreText.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, WindowSettings::CENTER_Y - 125.0f));
	scoreText.SetText("SCORE");
	
	currentScoreText.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	currentScoreText.SetCharacterSize(120);
	currentScoreText.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, WindowSettings::CENTER_Y));
	currentScoreText.SetFillColor(sf::Color::Yellow);
	currentScoreText.SetText(std::to_string(ManagerLocator::GetGameManager().GetCurrentScore()));

	quitButton.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	quitButton.SetCharacterSize(50);
	quitButton.SetText("EXIT");
	quitButton.SetSize(sf::Vector2f(400.0f, 150.0f));
	quitButton.SetBackgroundColor(sf::Color(55, 55, 55));
	quitButton.SetOutlineColor(sf::Color::White);
	quitButton.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, WindowSettings::CENTER_Y + 400.0f));
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
					ManagerLocator::GetStateManager().TransitionTo(std::make_unique<MainMenuState>());
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
	window.draw(scoreText);
	window.draw(currentScoreText);
	window.draw(quitButton);
}