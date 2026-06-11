#include "State/StartMenuState.h"

#include "ManagerLocator.h"
#include "Manager/RenderManager.h"
#include "Manager/ResourceManager.h"
#include "Manager/StateManager.h"
#include "Manager/ScoreManager.h"
#include "State/GameState.h"
#include "State/MainMenuState.h"
#include "WindowSettings.h"

StartMenuState::StartMenuState()
{
	Initialize();
}

void StartMenuState::Initialize()
{
	highscoreText.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	highscoreText.SetCharacterSize(100);
	highscoreText.SetText("HIGHSCORE");
	highscoreText.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, 150.0f));

	scoreText.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	scoreText.SetCharacterSize(120);
	scoreText.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, 300.0f));
	scoreText.SetFillColor(sf::Color::Yellow);
	
	int highscore = ManagerLocator::GetScoreManager().GetHighscore();

	if (ManagerLocator::GetScoreManager().HasHighscore())
	{
		scoreText.SetText(std::to_string(highscore));
	}
	else
	{
		scoreText.SetText("NO RECORD");
	}

	backButton.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	backButton.SetCharacterSize(50);
	backButton.SetText("BACK");
	backButton.SetSize(sf::Vector2f(400.0f, 150.0f));
	backButton.SetBackgroundColor(sf::Color(55, 55, 55));
	backButton.SetOutlineColor(sf::Color::White);
	backButton.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, WindowSettings::CENTER_Y + 400.0f));

	startButton.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	startButton.SetCharacterSize(70);
	startButton.SetText("START");
	startButton.SetSize(sf::Vector2f(600.0f, 200.0f));
	startButton.SetBackgroundColor(sf::Color(55, 55, 55));
	startButton.SetOutlineColor(sf::Color::White);
	startButton.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, WindowSettings::CENTER_Y));
}

void StartMenuState::HandleInput(sf::Event& event, sf::RenderWindow& window)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
	{
		if (event.key.code == sf::Keyboard::Escape)
		{
			ManagerLocator::GetStateManager().ChangeState(std::make_unique<MainMenuState>());
		}
		break;
	}
	case sf::Event::MouseButtonPressed:
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (startButton.IsHovered())
			{
				ManagerLocator::GetStateManager().TransitionTo(std::make_unique<GameState>());
			}
			if (backButton.IsHovered())
			{
				ManagerLocator::GetStateManager().ChangeState(std::make_unique<MainMenuState>());
			}
		}
		break;
	}
	}
}

void StartMenuState::Update(float deltaTime)
{
	startButton.Update();
	backButton.Update();
}

void StartMenuState::Render(sf::RenderWindow& window)
{
	window.setView(ManagerLocator::GetRenderManager().GetCamera().GetView());
	window.draw(tiles);
	window.setView(window.getDefaultView());
	window.draw(highscoreText);
	window.draw(scoreText);
	window.draw(startButton);
	window.draw(backButton);
}