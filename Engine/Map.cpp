#include "Map.h"
#include <assert.h>
#include "File.h"
#include "SpriteEffect.h"

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
	bool creatingRoad = false;
	int x = 0;
	int y = 0;

	for (int i = 0; i < ch.length() && y < height; i++)
	{
		if (ch[i] == 76 || ch[i] == 84 || ch[i] == 82 || ch[i] == 66)
		{
			if (continues)
			{
				tiles[x][y].AddRiver(ch[i]);
			}
			else if (creatingRoad)
			{
				tiles[x][y].AddRoad(ch[i]);
			}
		}
		else
		{
			if (continues)
			{
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
			if (creatingRoad)
			{
				creatingRoad = false;
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

		if (ch[i] == 57)
		{
			tileType = ch[i];
			tiles[x][y].AddType(std::stoi(tileType));
			creatingRoad = true;
		}

		if (ch[i] < 57 && ch[i] > 47)
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

void Map::Draw()
{
	DrawGrid();
	DrawTileTextures();
	DrawCharacter("Images/TileTextures/Character/Character.bmp");
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

void Map::DrawCharacter(const std::string fileName) const
{
	gfx.DrawSprite(characterPos.x * dimension + 1, +characterPos.y * dimension + 1, { "Images/TileTextures/Character/Character.bmp" }, SpriteEffect::Chroma(Colors::Black));
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

std::string Map::getTileType(const Pos & tilePos) const
{

	switch (tiles[characterPos.x][characterPos.y].GetType())
	{
	case 1:
		return ("Forest");
		break;
	case 2:
		return ("Mountain");
		break;
	case 3:
		return ("Swamp");
		break;
	case 4:
		return ("Plains");
		break;
	case 5:
		return ("Village");
		break;
	case 6:
		return ("Village");
		break;
	case 7:
		return ("Village");
		break;
	case 8:
		return ("Field");
		break;
	case 9:
		return ("Road");
		break;
	default:
		assert(false);
		return ("Error");
	}
}

Map::Tile::Tile()
{
	AddType(8);
}

const std::string Map::Tile::basePath = "Images/TileTextures";

void Map::Tile::AddType(int in_type)
{
	typeID = in_type;
	switch (in_type)
	{
	case 1:
		texture = { basePath + "/Nature/Forest.bmp" };
		timeCost = 3;
		break;
	case 2:
		texture = { basePath + "/Nature/Mountain.bmp" };
		passable = false;
		timeCost = 0;
		break;
	case 3:
		texture = { basePath + "/Nature/Swamp.bmp" };
		timeCost = 6;
		break;
	case 4:
		texture = { basePath + "/Error/Error.bmp" };
		timeCost = 2;
		break;
	case 5:
		texture = { basePath + "/Village/VillageSize1.bmp" };
		timeCost = 1;
		break;
	case 6:
		texture = { basePath + "/Village/VillageSize2.bmp" };
		timeCost = 1;
		break;
	case 7:
		texture = { basePath + "/Village/VillageSize3.bmp" };
		timeCost = 1;
		break;
	case 8:
		texture = { basePath + "/Village/Field.bmp" };
		timeCost = 2;
		break;
	case 9:
		texture = { basePath + "/Error/Error.bmp" };
		timeCost = 1;
		break;
	default:
		texture = { basePath + "/Error/Error.bmp" };
		timeCost = 0;
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

void Map::Tile::AddRoad(char side)
{
	switch (side)
	{
	case 76: //L
		roadLeft = true;
		break;
	case 84: //T
		roadTop = true;
		break;
	case 82: //R
		roadRight = true;
		break;
	case 66: //B
		roadBottom = true;
		break;
	}
}

void Map::Tile::Draw(int x, int y, Graphics & gfx) const
{
	if (typeID != 8 && typeID != 9)
	{
		gfx.DrawSprite(x, y, texture, SpriteEffect::Chroma(Colors::Black));
	}

	if (typeID == 8)
	{
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
	else if (typeID == 9)
	{
		if (roadLeft)
		{
			gfx.DrawSprite(x, y, { basePath + "/Road/LeftRoad.bmp" }, SpriteEffect::Chroma(Colors::Black));
		}
		if (roadTop)
		{
			gfx.DrawSprite(x, y, { basePath + "/Road/TopRoad.bmp" }, SpriteEffect::Chroma(Colors::Black));
		}
		if (roadRight)
		{
			gfx.DrawSprite(x, y, { basePath + "/Road/RightRoad.bmp" }, SpriteEffect::Chroma(Colors::Black));
		}
		if (roadBottom)
		{
			gfx.DrawSprite(x, y, { basePath + "/Road/LeftRoad.bmp" }, SpriteEffect::Chroma(Colors::Black));
		}
	}
}

bool Map::Tile::IsPassable() const
{
	return passable;
}

int Map::Tile::GetTimeCost() const
{
	return timeCost;
}

int Map::Tile::GetType() const
{
	return typeID;
}
