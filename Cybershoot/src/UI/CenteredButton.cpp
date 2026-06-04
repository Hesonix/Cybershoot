#include "UI/CenteredButton.h"
#include "ManagerLocator.h"
#include "Manager/RenderManager.h"

void CenteredButton::UpdateAlignment()
{
	sf::FloatRect bounds = background.getLocalBounds();

	background.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}

void CenteredButton::SetText(const std::string& text)
{
	buttonText.SetText(text);
}

void CenteredButton::SetPosition(sf::Vector2f position)
{
	background.setPosition(position);
	buttonText.SetPosition(position);
}

void CenteredButton::SetSize(sf::Vector2f size)
{
	background.setSize(size);
	UpdateAlignment();
}

void CenteredButton::SetBackgroundColor(sf::Color color)
{
	background.setFillColor(color);
}

void CenteredButton::SetOutlineColor(sf::Color color)
{
	background.setOutlineThickness(5.0f);
	background.setOutlineColor(color);
}

void CenteredButton::SetFont(const sf::Font& font)
{
	buttonText.SetFont(font);
}

void CenteredButton::SetCharacterSize(unsigned int size)
{
	buttonText.SetCharacterSize(size);
}

void CenteredButton::Update()
{
	sf::Vector2i mousePosition = ManagerLocator::GetRenderManager().GetMousePosition();

	isHovered = background.getGlobalBounds().contains(
		static_cast<float>(mousePosition.x),
		static_cast<float>(mousePosition.y)
	);

	if (isHovered)
	{
		background.setOutlineThickness(5.0f);
	}
	else
	{
		background.setOutlineThickness(0.0f);
	}
}

void CenteredButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background);
	target.draw(buttonText);
}
