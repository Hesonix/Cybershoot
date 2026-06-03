#pragma once

#include "CenteredText.h"

class CenteredButton : public sf::Drawable
{
private:
	CenteredText buttonText;
	sf::RectangleShape background;

	bool isHovered = false;

	void UpdateAlignment();
public:
	void SetText(const std::string& text);
	void SetFont(const sf::Font& font);
	void SetCharacterSize(unsigned int size);
	void SetPosition(sf::Vector2f position);
	void SetSize(sf::Vector2f size);
	void SetBackgroundColor(sf::Color color);
	void SetOutlineColor(sf::Color color);

	bool IsHovered() { return isHovered; }

	void Update();
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};