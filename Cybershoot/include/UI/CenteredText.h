#pragma once

#include "SFML/Graphics.hpp"

class CenteredText : public sf::Drawable
{
private:
	sf::Text text;

	bool isVisible = true;

	void UpdateAlignment();
public:
	void SetFont(const sf::Font& font);
	void SetText(const std::string& newText);
	void SetCharacterSize(unsigned int size);
	void SetPosition(sf::Vector2f position);
	void Show();
	void Hide();
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};