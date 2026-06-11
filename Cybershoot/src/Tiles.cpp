#include "Tiles.h"

#include "ManagerLocator.h"
#include "Manager/ResourceManager.h"

Tiles::Tiles()
{
	sf::Sprite tilePrototype;
	sf::Texture& texture = ManagerLocator::GetResourceManager().GetTextureByName("floor");
	tilePrototype.setTexture(texture);
	tilePrototype.setOrigin(TILE_CENTER_X, TILE_CENTER_Y);

	tiles.resize(GRID_SIZE, std::vector<sf::Sprite>(GRID_SIZE));

	for (int x = 0; x < GRID_SIZE; x++)
	{
		for (int y = 0; y < GRID_SIZE; y++)
		{
			tiles[x][y] = tilePrototype;
			tiles[x][y].setPosition(
				(x - CENTER_OFFSET) * TILE_SIZE_X,
				(y - CENTER_OFFSET) * TILE_SIZE_Y
			);
		}
	}

	currentCenterTile = { 0, 0 };
}

void Tiles::Update(sf::Vector2f playerPosition)
{
	int playerTileX = static_cast<int>(playerPosition.x / TILE_SIZE_X);
	int playerTileY = static_cast<int>(playerPosition.y / TILE_SIZE_Y);

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
					worldTileX * TILE_SIZE_X,
					worldTileY * TILE_SIZE_X
				);
			}
		}
	}
}

void Tiles::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int x = 0; x < GRID_SIZE; x++)
	{
		for (int y = 0; y < GRID_SIZE; y++)
		{
			target.draw(tiles[x][y]);
		}
	}
}