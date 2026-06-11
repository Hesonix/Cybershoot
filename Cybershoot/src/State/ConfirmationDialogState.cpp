#include "State/ConfirmationDialogState.h"

#include "ManagerLocator.h"
#include "Manager/ResourceManager.h"
#include "Manager/StateManager.h"
#include "WindowSettings.h"

ConfirmationDialogState::ConfirmationDialogState(const std::string& message, std::function<void()> onConfirm, std::function<void()> onCancel)
	: message(message)
	, onConfirm(onConfirm)
	, onCancel(onCancel)
{
	Initialize();
}

void ConfirmationDialogState::Initialize()
{
	background.setSize(sf::Vector2f(800.0f, 500.0f));
	background.setOrigin(400.0f, 250.0f);
	background.setPosition(WindowSettings::CENTER_X, WindowSettings::CENTER_Y);
	background.setFillColor(sf::Color(0, 0, 0, 200));

	messageText.SetText(message);
	messageText.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	messageText.SetCharacterSize(50);
	messageText.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, WindowSettings::CENTER_Y - 100.0f));

	yesButton.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	yesButton.SetCharacterSize(50);
	yesButton.SetText("YES");
	yesButton.SetSize(sf::Vector2f(200.0f, 150.0f));
	yesButton.SetBackgroundColor(sf::Color(55, 55, 55));
	yesButton.SetOutlineColor(sf::Color::White);
	yesButton.SetPosition(sf::Vector2f(WindowSettings::CENTER_X - 200.0f, WindowSettings::CENTER_Y + 50.0f));

	noButton.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	noButton.SetCharacterSize(50);
	noButton.SetText("NO");
	noButton.SetSize(sf::Vector2f(200.0f, 150.0f));
	noButton.SetBackgroundColor(sf::Color(55, 55, 55));
	noButton.SetOutlineColor(sf::Color::White);
	noButton.SetPosition(sf::Vector2f(WindowSettings::CENTER_X + 200.0f, WindowSettings::CENTER_Y + 50.0f));
}

void ConfirmationDialogState::HandleInput(sf::Event& event, sf::RenderWindow& window)
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
				if (yesButton.IsHovered())
				{
					onConfirm();
				}
				else if (noButton.IsHovered())
				{
					onCancel();
				}
			}
			break;
		}
	}
}

void ConfirmationDialogState::Update(float deltaTime)
{
	yesButton.Update();
	noButton.Update();
}

void ConfirmationDialogState::Render(sf::RenderWindow& window)
{
	window.draw(background);
	window.draw(messageText);
	window.draw(yesButton);
	window.draw(noButton);
}