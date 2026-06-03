#include "TileManager.h"

#include <iostream>

#include "Player.h"

TileManager::TileManager()
{
	texture.loadFromFile("res/textures/floor.png");

	tilePrototype.setTexture(texture);

	sf::Vector2u textureSize = texture.getSize();
	tileSize = sf::Vector2f(
		static_cast<float>(textureSize.x),
		static_cast<float>(textureSize.y)
	);

	tilePrototype.setOrigin(tileSize.x / 2.0f, tileSize.y / 2.0f);

	tiles.resize(GRID_SIZE, std::vector<sf::Sprite>(GRID_SIZE));

	currentCenterTile = { 0, 0 };

	for (int x = 0; x < GRID_SIZE; x++)
	{
		for (int y = 0; y < GRID_SIZE; y++)
		{
			tiles[x][y] = tilePrototype;
			tiles[x][y].setPosition(
				(x - CENTER_OFFSET) * tileSize.x,
				(y - CENTER_OFFSET) * tileSize.y
			);
		}
	}
}

void TileManager::Update()
{
	sf::Vector2f playerPosition = Player::GetInstance().GetPosition();

	int playerTileX = static_cast<int>(playerPosition.x / tileSize.x);
	int playerTileY = static_cast<int>(playerPosition.y / tileSize.y);

	if (playerTileX != currentCenterTile.x || playerTileY != currentCenterTile.y)
	{
		currentCenterTile = { playerTileX, playerTileY };

		for (int x = 0; x < GRID_SIZE; x++)
		{
			for (int y = 0; y < GRID_SIZE; y++)
			{
				int worldTileX = currentCenterTile.x + (x - CENTER_OFFSET);
				int worldTileY = currentCenterTile.y + (y - CENTER_OFFSET);

				tiles[x][y].setPosition(
					worldTileX * tileSize.x,
					worldTileY * tileSize.y
				);
			}
		}
	}
}

void TileManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int x = 0; x < GRID_SIZE; x++)
	{
		for (int y = 0; y < GRID_SIZE; y++)
		{
			target.draw(tiles[x][y]);
		}
	}
}