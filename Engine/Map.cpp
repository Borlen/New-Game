#include "Map.h"
#include <assert.h>

Map::Map(Pos & in_charPos, Graphics & in_gfx, Time& in_time)
	:
	characterPos(in_charPos),
	gfx(in_gfx),
	time(in_time)
{
}

void Map::DrawGrid() const
{
	{
		for (int y = 0; y <= height * dimension; y += dimension)
		{
			for (int x = 0; x < width * dimension; x++)
			{
				gfx.PutPixel(x, y, color);
			}
		}
		for (int x = 0; x <= width * dimension; x += dimension)
		{
			for (int y = 0; y < height * dimension; y++)
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
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			tiles[x][y].Draw(x * dimension, y * dimension, gfx);
		}
	}
}

void Map::MoveCharacter(Pos& dir) const
{
	if (!(dir.x + characterPos.x < 0 || dir.x + characterPos.x >= width || dir.y + characterPos.y < 0 || dir.y + characterPos.y >= height))
	{
		if (tiles[dir.x + characterPos.x][dir.y + characterPos.y].IsPassable())
		{
			characterPos += dir;
			time.Add(1,'h');
		}
	}
}

int Map::GetDimension() const
{
	return dimension;
}

int Map::GetWidth() const
{
	return width;
}

int Map::GetHeight() const
{
	return height;
}

Map::Tile::Tile()
{
	AddType(9);  //For testing purposes, remake later
}

void Map::Tile::AddType(int in_type)
{
	typeID = in_type;
	switch (in_type)
	{
	case 1:
		type.Draw = &SpriteCodex::DrawForest;
		break;
	case 2:
		type.Draw = &SpriteCodex::DrawMountain;
		type.passable = false;
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
	if (typeID != 8)
	{
		type.Draw(x, y, gfx);
	}

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

bool Map::Tile::IsPassable() const
{
	return type.passable;
}
