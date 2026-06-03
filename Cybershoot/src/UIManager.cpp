#include "UIManager.h"

#include "ManagerLocator.h"
#include "ResourceManager.h"

UIManager::UIManager()
{
	gameTimeText.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	gameTimeText.SetText("00:00");
	gameTimeText.SetCharacterSize(100);
	gameTimeText.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, 50.0f));

	healthBar.setPosition(25.0f, 25.0f);
	healthBar.setSize(sf::Vector2f(600.0f, 50.0f));
	healthBar.setFillColor(sf::Color::Green);

	healthBarBackground.setPosition(25.0f, 25.0f);
	healthBarBackground.setSize(sf::Vector2f(600.0f, 50.0f));
	healthBarBackground.setFillColor(sf::Color(50, 50, 50));
	healthBarBackground.setOutlineColor(sf::Color::Black);
	healthBarBackground.setOutlineThickness(5.0f);

	weaponAmmoText.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	weaponAmmoText.SetText("0");
	weaponAmmoText.SetCharacterSize(80);
	weaponAmmoText.SetPosition(sf::Vector2f(WindowSettings::WIDTH - 150.0f, WindowSettings::HEIGHT - 100.0f));

	reloadingText.SetFont(ManagerLocator::GetResourceManager().GetFontByName("UI"));
	reloadingText.SetText("Reloading...");
	reloadingText.SetCharacterSize(40);
	reloadingText.SetPosition(sf::Vector2f(WindowSettings::CENTER_X, WindowSettings::CENTER_Y));
	reloadingText.Hide();
}

void UIManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameTimeText);
	target.draw(healthBarBackground);
	target.draw(healthBar);
	target.draw(weaponAmmoText);
	target.draw(reloadingText);
}

void UIManager::UpdateGameTimeText(float time)
{
	int timeInSeconds = static_cast<int>(time);
	int minutes = timeInSeconds / 60;
	int seconds = timeInSeconds % 60;
	std::string finalString;
	if (minutes < 10) finalString += "0";
	finalString += std::to_string(minutes) + ':';
	if (seconds < 10) finalString += '0';
	finalString += std::to_string(seconds);

	gameTimeText.SetText(finalString);
}

void UIManager::UpdateHealthBar(int health)
{
	healthBar.setSize(sf::Vector2f(health * 600.0f / 100.0f, 50.0f));
}

void UIManager::UpdateAmmoText(int ammoInMagazine, int totalReserveAmmo)
{
	weaponAmmoText.SetText(std::to_string(ammoInMagazine) + " / " + std::to_string(totalReserveAmmo));
}

void UIManager::UpdateReloadingText(bool isVisible)
{
	isVisible ? reloadingText.Show() : reloadingText.Hide();
}