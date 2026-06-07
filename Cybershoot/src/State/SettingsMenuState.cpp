#include "State/SettingsMenuState.h"

#include "ManagerLocator.h"
#include "Manager/StateManager.h"
#include "Manager/ResourceManager.h"
#include "Manager/RenderManager.h"
#include "Manager/TileManager.h"
#include "WindowSettings.h"
#include "State/MainMenuState.h"
#include "Transition.h"

SettingsMenuState::SettingsMenuState()
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
	case sf::Event::MouseButtonPressed:
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (backButton.IsHovered())
			{
				Transition::GetInstance().FadeInOut([]() {
					ManagerLocator::GetStateManager().ChangeState(std::make_unique<MainMenuState>());
				});
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
	window.draw(ManagerLocator::GetTileManager());
	window.setView(ManagerLocator::GetRenderManager().GetWindow().getDefaultView());
	window.draw(settingsText);
	window.draw(toBeAddedText);
	window.draw(backButton);
}