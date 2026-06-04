#pragma once

#include "State.h"
#include "UI/CenteredText.h"
#include "UI/CenteredButton.h"
#include "WindowSettings.h"

class MainMenuState : public State
{
private:
	CenteredText titleText;
	CenteredButton playButton;
	CenteredButton quitButton;
public:
	MainMenuState();

	void HandleInput(sf::Event& event, sf::RenderWindow& window) override;
	void Update(float deltaTime) override;
	void Render(sf::RenderWindow& window) override;
};