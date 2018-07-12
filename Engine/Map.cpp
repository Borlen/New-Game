#include "Map.h"
#include <assert.h>

Map::Map(Pos & in_charPos, Graphics & in_gfx)
	:
	characterPos(in_charPos),
	gfx(in_gfx)
{
}

void Map::DrawGrid() const
{
	{
		for (int y = 0; y <= mapHeight * dimension; y += dimension)
		{
			for (int x = 0; x < mapWidth * dimension; x++)
			{
				gfx.PutPixel(x, y, color);
			}
		}
		for (int x = 0; x <= mapWidth * dimension; x += dimension)
		{
			for (int y = 0; y < mapHeight * dimension; y++)
			{
				gfx.PutPixel(x, y, color);
			}
		}
	}
}

void Map::DrawCharacter() const
{
	//SpriteCodex::DrawCharacterWithHorse(int(characterPos.x*dimension), int(characterPos.y*dimension), gfx);
	SpriteCodex::DrawCharacter(int(characterPos.x*dimension), int(characterPos.y*dimension), gfx);
}

void Map::DrawTileTextures() const
{
	for (int x = 0; x < mapWidth; x++)
	{
		for (int y = 0; y < mapHeight; y++)
		{
			Tiles[x][y].Draw(x * dimension, y * dimension, gfx);
		}
	}
}

Map::Tile::Tile()
{
	AddType(9);  //For testing purposes, remake later
}

void Map::Tile::AddType(int in_type)
{
	switch (in_type)
	{
	case 1:
		type.Draw = &SpriteCodex::DrawForest;
		break;
	case 2:
		type.Draw = &SpriteCodex::DrawMountain;
		break;
	case 3:
		type.Draw = &SpriteCodex::DrawSwamp;
		break;
	case 4:
		type.Draw = &SpriteCodex::DrawLeftRoad;
		break;
	case 5:
		type.Draw = &SpriteCodex::DrawTopRoad;
		break;
	case 6:
		type.Draw = &SpriteCodex::DrawRightRoad;
		break;
	case 7:
		type.Draw = &SpriteCodex::DrawBottomRoad;
		break;
	case 8:
		break;
	case 9:
		type.Draw = &SpriteCodex::DrawVillageSize1;
		break;
	case 10:
		type.Draw = &SpriteCodex::DrawVillageSize2;
		break;
	case 11:
		type.Draw = &SpriteCodex::DrawVillageSize3;
		break;
	case 12:
		type.Draw = &SpriteCodex::DrawField;
		break;
	default:
		assert(false);
		break;
	}
}

void Map::Tile::Draw(int x, int y, Graphics & gfx) const
{
	type.Draw(x, y, gfx);

	if (riverLeft)
	{
		for (int i = y + 1; i < y + dimension; i++)
		{
			gfx.PutPixel(x, i, 0, 180, 255);
		}
	}
	if (riverTop)
	{
		for (int i = x + 1; i < x + dimension; i++)
		{
			gfx.PutPixel(i, y, 0, 180, 255);
		}
	}
	if (riverRight)
	{
		for (int i = y + 1; i < y + dimension; i++)
		{
			gfx.PutPixel(x + dimension, i, 0, 180, 255);
		}
	}
	if (riverBottom)
	{
		for (int i = x + 1; i < x + dimension; i++)
		{
			gfx.PutPixel(i, y + dimension, 0, 180, 255);
		}
	}
}
