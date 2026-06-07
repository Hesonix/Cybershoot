#include "State/MainMenuState.h"

#include "ManagerLocator.h"
#include "Manager/ResourceManager.h"
#include "Manager/StateManager.h"
#include "Manager/RenderManager.h"
#include "State/GameState.h"
#include "State/SettingsMenuState.h"
#include "WindowSettings.h"
#include "Transition.h"
#include "State/ConfirmationDialogState.h"

MainMenuState::MainMenuState()
{
	ManagerLocator::GetRenderManager().GetCamera().SetPosition(sf::Vector2f(0.0f, 0.0f));
	ManagerLocator::GetTileManager().Reset();

	titleText.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	titleText.SetCharacterSize(100);
	titleText.SetText("CYBERSHOOT");
	titleText.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, 100.0f));

	playButton.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	playButton.SetCharacterSize(50);
	playButton.SetText("PLAY");
	playButton.SetSize(sf::Vector2f(400.0f, 150.0f));
	playButton.SetBackgroundColor(sf::Color(55, 55, 55));
	playButton.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, WindowSettings::CENTER_Y - 200.0f));
	
	settingsButton.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	settingsButton.SetCharacterSize(50);
	settingsButton.SetText("SETTINGS");
	settingsButton.SetSize(sf::Vector2f(400.0f, 150.0f));
	settingsButton.SetBackgroundColor(sf::Color(55, 55, 55));
	settingsButton.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, WindowSettings::CENTER_Y));

	quitButton.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	quitButton.SetCharacterSize(50);
	quitButton.SetText("QUIT");
	quitButton.SetSize(sf::Vector2f(400.0f, 150.0f));
	quitButton.SetBackgroundColor(sf::Color(55, 55, 55));
	quitButton.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, WindowSettings::CENTER_Y + 200.0f));
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
					Transition::GetInstance().FadeInOut([]() {
						ManagerLocator::GetStateManager().ChangeState(std::make_unique<GameState>());
					});
				}
				else if (settingsButton.IsHovered())
				{
					Transition::GetInstance().FadeInOut([]() {
						ManagerLocator::GetStateManager().ChangeState(std::make_unique<SettingsMenuState>());
					});
				}
				else if (quitButton.IsHovered())
				{
					ManagerLocator::GetStateManager().PushState(std::make_unique<ConfirmationDialogState>(
						"Leave the game?",
						[&]() { Transition::GetInstance().FadeIn([&]() { window.close(); }); },
						[]() { ManagerLocator::GetStateManager().PopState(); }
					));
				}
			}
			break;
		}
	}
}

void MainMenuState::Update(float deltaTime)
{
	playButton.Update();
	settingsButton.Update();
	quitButton.Update();
}

void MainMenuState::Render(sf::RenderWindow& window)
{
	window.setView(ManagerLocator::GetRenderManager().GetCamera().GetView());
	window.draw(ManagerLocator::GetTileManager());
	window.setView(ManagerLocator::GetRenderManager().GetWindow().getDefaultView());
	window.draw(titleText);
	window.draw(playButton);
	window.draw(settingsButton);
	window.draw(quitButton);
}