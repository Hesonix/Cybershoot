#include "State/SettingsMenuState.h"

#include "ManagerLocator.h"
#include "Manager/StateManager.h"
#include "Manager/ResourceManager.h"
#include "Manager/RenderManager.h"
#include "State/MainMenuState.h"
#include "WindowSettings.h"

SettingsMenuState::SettingsMenuState()
{
	Initialize();
}

void SettingsMenuState::Initialize()
{
	settingsText.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	settingsText.SetCharacterSize(100);
	settingsText.SetText("SETTINGS");
	settingsText.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, 100.0f));

	toBeAddedText.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	toBeAddedText.SetCharacterSize(100);
	toBeAddedText.SetText("TO BE ADDED");
	toBeAddedText.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, WindowSettings::CENTER_Y));


	backButton.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	backButton.SetCharacterSize(50);
	backButton.SetText("BACK");
	backButton.SetSize(sf::Vector2f(400.0f, 150.0f));
	backButton.SetBackgroundColor(sf::Color(55, 55, 55));
	backButton.SetOutlineColor(sf::Color::White);
	backButton.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, WindowSettings::CENTER_Y + 400.0f));
}

void SettingsMenuState::HandleInput(sf::Event& event, sf::RenderWindow& window)
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
				if (backButton.IsHovered())
				{
					ManagerLocator::GetStateManager().ChangeState(std::make_unique<MainMenuState>());
				}
			}
			break;
		}
	}
}

void SettingsMenuState::Update(float deltaTime)
{
	backButton.Update();
}

void SettingsMenuState::Render(sf::RenderWindow& window)
{
	window.setView(ManagerLocator::GetRenderManager().GetCamera().GetView());
	window.draw(tiles);
	window.setView(window.getDefaultView());
	window.draw(settingsText);
	window.draw(toBeAddedText);
	window.draw(backButton);
}