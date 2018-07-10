#include "Board.h"
#include <assert.h>
#include "SpriteCodex.h"

Board::Board(Graphics & in_gfx)
	:
	gfx(in_gfx)
{
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			Tiles[i][j] = 1;
		}
	}
	Tiles[1][1] = 2;
	Tiles[1][2] = 3;
	Tiles[1][3] = 4;
	Tiles[1][4] = 5;
}

void Board::Draw(Graphics & gfx) const
{
	for (int y = 0; y < mapHeight * dimension + 1; y += dimension)
	{
		for (int x = 0; x < mapWidth * dimension; x++)
		{
			gfx.PutPixel(x,y,color);
		}
	}
	for (int x = 0; x < mapWidth * dimension + 1; x += dimension)
	{
		for (int y = 0; y < mapHeight * dimension; y++)
		{
			gfx.PutPixel(x, y, color);
		}
	}

	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			switch (Tiles[i][j])
			{
			case 1:
				break;
			case 2:
				SpriteCodex::DrawPlains(dimension * i, dimension * j, gfx);
				break;
			case 3:
				SpriteCodex::DrawForest(dimension * i, dimension * j, gfx);;
				break;
			case 4:
				SpriteCodex::DrawRiver(dimension * i, dimension * j, gfx);;
				break;
			case 5:
				SpriteCodex::DrawMountain(dimension * i, dimension * j, gfx);;
				break;
			}
		}
	}
}

int Board::GetDimension() const
{
	return dimension;
}

Vec2 Board::GetMapSize() const
{
	return Vec2(float(mapWidth), float(mapHeight));
}

int Board::GetTileType(const Vec2& moveTo) const
{
	if (moveTo.x < 0 || moveTo.y < 0 || moveTo.x > mapWidth || moveTo.y > mapHeight)
	{
		return 0;
	}
		return Tiles[int(moveTo.x)][int(moveTo.y)];
}