#include "Map.h"
#include <assert.h>
#include "File.h"

Map::Map(Pos & in_charPos, Graphics & in_gfx, Time& in_time)
	:
	characterPos(in_charPos),
	gfx(in_gfx),
	time(in_time)
{
	Load("map.txt"); //For testing purposes
}

void Map::Load(std::string filePath)
{
	std::string ch = File::GetString(filePath);
	std::string tileType;
	bool continues = false;
	int x = 0;
	int y = 0;

	for (int i = 0; i < ch.length() && y < height; i++)
	{
		if (ch[i] == 76 || ch[i] == 84 || ch[i] == 82 || ch[i] == 66)
		{
			tiles[x][y].AddRiver(ch[i]);
		}

		if (ch[i] < 58 && ch[i] > 47)
		{

			if (continues)
			{
				tileType += ch[i];
			}
			else
			{
				tileType = ch[i];
				continues = true;
			}

		}
		else
		{
			if (continues)
			{
				tiles[x][y].AddType(std::stoi(tileType));
				continues = false;

				if (x == width - 1)
				{
					x -= width - 1;
					y++;
				}
				else
				{
					x++;
				}
			}
		}
	}
	if (y < height) 
	{
		//Add warning?
	}
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
			time.Add(tiles[dir.x + characterPos.x][dir.y + characterPos.y].GetTimeCost(),'h');
			characterPos += dir;
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
	AddType(8);
}

void Map::Tile::AddType(int in_type)
{
	typeID = in_type;
	switch (in_type)
	{
	case 1:
		type.Draw = &SpriteCodex::DrawForest;
		type.timeCost = 3;
		break;
	case 2:
		type.Draw = &SpriteCodex::DrawMountain;
		type.passable = false;
		type.timeCost = 0;
		break;
	case 3:
		type.Draw = &SpriteCodex::DrawSwamp;
		type.timeCost = 6;
		break;
	case 4:
		type.timeCost = 2;
		break;
	case 5:
		type.Draw = &SpriteCodex::DrawVillageSize1;
		type.timeCost = 1;
		break;
	case 6:
		type.Draw = &SpriteCodex::DrawVillageSize2;
		type.timeCost = 1;
		break;
	case 7:
		type.Draw = &SpriteCodex::DrawVillageSize3;
		type.timeCost = 1;
		break;
	case 8:
		type.Draw = &SpriteCodex::DrawField;
		type.timeCost = 2;
		break;
	case 9:
		type.Draw = &SpriteCodex::DrawLeftRoad;
		type.timeCost = 1;
		break;
	case 10:
		type.Draw = &SpriteCodex::DrawLeftTopRoad;
		type.timeCost = 1;
		break;
	case 11:
		type.Draw = &SpriteCodex::DrawLeftRightRoad;
		type.timeCost = 1;
		break;
	case 12:
		type.Draw = &SpriteCodex::DrawLeftBottomRoad;
		type.timeCost = 1;
		break;
	case 13:
		type.Draw = &SpriteCodex::DrawLeftBottomRightRoad;
		type.timeCost = 1;
		break;
	case 14:
		type.Draw = &SpriteCodex::DrawLeftTopRightRoad;
		type.timeCost = 1;
		break;
	case 15:
		type.Draw = &SpriteCodex::DrawLeftTopBottomRoad;
		type.timeCost = 1;
		break;
	case 16:
		type.Draw = &SpriteCodex::DrawLeftTopRightBottomRoad;
		type.timeCost = 1;
		break;
	case 17:
		type.Draw = &SpriteCodex::DrawTopBottomRoad;
		type.timeCost = 1;
		break;
	case 18:
		type.Draw = &SpriteCodex::DrawTopRoad;
		type.timeCost = 1;
		break;
	case 19:
		type.Draw = &SpriteCodex::DrawTopRightRoad;
		type.timeCost = 1;
		break;
	case 20:
		type.Draw = &SpriteCodex::DrawTopBottomRoad;
		type.timeCost = 1;
		break;
	case 21:
		type.Draw = &SpriteCodex::DrawTopRightBottomRoad;
		type.timeCost = 1;
		break;
	case 22:
		type.Draw = &SpriteCodex::DrawRightRoad;
		type.timeCost = 1;
		break;
	case 23:
		type.Draw = &SpriteCodex::DrawRightBottomRoad;
		type.timeCost = 1;
		break;
	case 24:
		type.Draw = &SpriteCodex::DrawBottomRoad;
		type.timeCost = 1;
		break;
	default:
		assert(false);
		break;
	}
}

void Map::Tile::AddRiver(char side)
{
	switch (side)
	{
	case 76: //L
		riverLeft = true;
			break;
	case 84: //T
		riverTop = true;
		break;
	case 82: //R
		riverRight = true;
		break;
	case 66: //B
		riverBottom = true;
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

int Map::Tile::GetTimeCost() const
{
	return type.timeCost;
}
