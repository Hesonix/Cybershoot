#pragma once

#include "SFML/Graphics.hpp"

class Tiles : public sf::Drawable
{
private:
	static constexpr int GRID_SIZE = 5;
	static constexpr int CENTER_OFFSET = GRID_SIZE / 2;
	static constexpr float TILE_SIZE_X = 800.0f;
	static constexpr float TILE_SIZE_Y = 800.0f;
	static constexpr float TILE_CENTER_X = 400.0f;
	static constexpr float TILE_CENTER_Y = 400.0f;

	std::vector<std::vector<sf::Sprite>> tiles;

	sf::Vector2i currentCenterTile;
public:
	Tiles();

	void Update(sf::Vector2f playerPosition);
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};