#pragma once

#include "State.h"
#include "Tiles.h"
#include "UI/CenteredText.h"
#include "UI/CenteredButton.h"
#include "WindowSettings.h"

class StartMenuState : public State
{
private:
	CenteredText highscoreText;
	CenteredText scoreText;
	CenteredButton startButton;
	CenteredButton backButton;

	Tiles tiles;

	void Initialize();
public:
	StartMenuState();

	void HandleInput(sf::Event& event, sf::RenderWindow& window) override;
	void Update(float deltaTime) override;
	void Render(sf::RenderWindow& window) override;
};