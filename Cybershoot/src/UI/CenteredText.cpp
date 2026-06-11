#include "UI/CenteredText.h"

void CenteredText::UpdateAlignment()
{
	sf::FloatRect bounds = text.getLocalBounds();

	text.setOrigin(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);
}

void CenteredText::SetFont(const sf::Font& font)
{
	text.setFont(font);
	UpdateAlignment();
}

void CenteredText::SetText(const std::string& newText)
{
	text.setString(newText);
	UpdateAlignment();
}

void CenteredText::SetCharacterSize(unsigned int size)
{
	text.setCharacterSize(size);
	UpdateAlignment();
}

void CenteredText::SetFillColor(sf::Color color)
{
	text.setFillColor(color);
}

void CenteredText::SetPosition(sf::Vector2f position)
{
	text.setPosition(position);
}

void CenteredText::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (isVisible)
	{
		target.draw(text);
	}
}

void CenteredText::Show()
{
	isVisible = true;
}

void CenteredText::Hide()
{
	isVisible = false;
}