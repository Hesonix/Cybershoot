#pragma once

#include "State.h"
#include "Tiles.h"
#include "UI/CenteredText.h"
#include "UI/CenteredButton.h"
#include "WindowSettings.h"

class SettingsMenuState : public State
{
private:
	CenteredText settingsText;
	CenteredText toBeAddedText;
	CenteredButton backButton;

	Tiles tiles;

	void Initialize();
public:
	SettingsMenuState();

	void HandleInput(sf::Event& event, sf::RenderWindow& window) override;
	void Update(float deltaTime) override;
	void Render(sf::RenderWindow& window) override;
};