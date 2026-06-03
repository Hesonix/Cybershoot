#pragma once

#include "SFML/Graphics.hpp"

#include "CenteredText.h"

#include "WindowSettings.h"

class UIManager : public sf::Drawable
{
private:
	CenteredText gameTimeText; 
	sf::RectangleShape healthBar;
	sf::RectangleShape healthBarBackground;
	CenteredText weaponAmmoText;
	CenteredText reloadingText;
public:
	UIManager();

	void UpdateGameTimeText(float gameTime);
	void UpdateHealthBar(int health);
	void UpdateAmmoText(int ammoInMagazine, int totalReservedAmmo);
	void UpdateReloadingText(bool isVisible);
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};