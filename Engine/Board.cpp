#include "Board.h"
#include <assert.h>
#include "SpriteCodex.h"

Board::Board(Graphics & in_gfx)
	:
	gfx(in_gfx)
{
	Tiles[1][1].properties[0] = 1;
	Tiles[1][2].properties[0] = 2;
	Tiles[1][3].properties[0] = 3;
	Tiles[1][4].properties[0] = 4;
	Tiles[1][5].properties[0] = 5;
	Tiles[1][6].properties[0] = 6;
	Tiles[1][7].properties[0] = 7;
	Tiles[1][8].properties[0] = 8;
	Tiles[1][9].properties[0] = 9;
	Tiles[1][10].properties[0] = 10;
	Tiles[1][11].properties[0] = 11;
}

void Board::Draw(Graphics & gfx) const
{
	for (int y = 0; y <= mapHeight * dimension; y += dimension)
	{
		for (int x = 0; x < mapWidth * dimension; x++)
		{
			gfx.PutPixel(x,y,color);
		}
	}
	for (int x = 0; x <= mapWidth * dimension; x += dimension)
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
			switch (Tiles[i][j].properties[0])
			{
			case 1:
				SpriteCodex::DrawForest(dimension * i, dimension * j, gfx);
				break;
			case 2:
				SpriteCodex::DrawMountain(dimension * i, dimension * j, gfx);
				break;
			case 3:
				SpriteCodex::DrawSwamp(dimension * i, dimension * j, gfx);
				break;
			case 4:
				SpriteCodex::DrawLeftRoad(dimension * i, dimension * j, gfx);
				break;
			case 5:
				SpriteCodex::DrawTopRoad(dimension * i, dimension * j, gfx);
				break;
			case 6:
				SpriteCodex::DrawRightRoad(dimension * i, dimension * j, gfx);
				break;
			case 7:
				SpriteCodex::DrawBottomRoad(dimension * i, dimension * j, gfx);
				break;
			case 9:
				SpriteCodex::DrawVillageSize1(dimension * i, dimension * j, gfx);
				break;
			case 10:
				SpriteCodex::DrawVillageSize2(dimension * i, dimension * j, gfx);
				break;
			case 11:
				SpriteCodex::DrawVillageSize3(dimension * i, dimension * j, gfx);
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
	return Tiles[int(moveTo.x)][int(moveTo.y)].properties[0];
}


/*
0 = Map Border
1 = Forest
2 = Mountain
3 = Swamp
4 = LeftRoad
5 = TopRoad
6 = RightRoad
7 = BottomRoad
8 = Field
9 = Village Size 1
10 = Village Size 2
11 = Village Size 3
*/