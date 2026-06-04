#pragma once

#include "State.h"
#include "State/GameState.h"
#include "UI/CenteredText.h"
#include "UI/CenteredButton.h"

class PauseState : public State
{
private:
	sf::RectangleShape background;
	CenteredText pausedText;
	CenteredButton resumeButton;
	CenteredButton quitButton;
public:
	PauseState();

	void HandleInput(sf::Event& event, sf::RenderWindow& window) override;
	void Update(float deltaTime) override;
	void Render(sf::RenderWindow& window) override;
};