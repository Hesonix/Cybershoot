#pragma once

#include "State.h"
#include "Tiles.h"
#include "UI/CenteredText.h"
#include "UI/CenteredButton.h"

class MainMenuState : public State
{
private:
	CenteredText titleText;
	CenteredButton playButton;
	CenteredButton settingsButton;
	CenteredButton quitButton;

	Tiles tiles;

	void Initialize();
public:
	MainMenuState();

	void HandleInput(sf::Event& event, sf::RenderWindow& window) override;
	void Update(float deltaTime) override;
	void Render(sf::RenderWindow& window) override;
};