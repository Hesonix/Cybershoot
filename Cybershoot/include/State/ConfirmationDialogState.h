#pragma once

#include "State/State.h"
#include <functional>
#include "UI/CenteredText.h"
#include "UI/CenteredButton.h"

class ConfirmationDialogState : public State
{
private:
	sf::RectangleShape background;
	CenteredText messageText;
	CenteredButton yesButton;
	CenteredButton noButton;
	std::function<void()> onConfirm;
	std::function<void()> onCancel;
public:
	ConfirmationDialogState(const std::string& message, std::function<void()> onConfirm, std::function<void()> onCancel);

	void HandleInput(sf::Event& event, sf::RenderWindow& window) override;
	void Update(float deltaTime) override;
	void Render(sf::RenderWindow& window) override;
};