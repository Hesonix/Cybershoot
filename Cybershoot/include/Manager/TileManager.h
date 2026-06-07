#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

class TileManager : public sf::Drawable
{
private:
	static constexpr int GRID_SIZE = 5;
	static constexpr int CENTER_OFFSET = GRID_SIZE / 2;

	std::vector<std::vector<sf::Sprite>> tiles;

	sf::Sprite tilePrototype;

	sf::Vector2f tileSize;
	sf::Vector2i currentCenterTile;
public:
	void Init();

	void Reset();

	void Update(sf::Vector2f playerPosition);
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};