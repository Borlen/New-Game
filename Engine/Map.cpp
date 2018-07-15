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
	bool xSizeIsSet = false;
	bool ySizeIsSet = false;
	int x = 0;
	int y = 0;

	for (int i = 0; i < ch.length() && y < height; i++)
	{
		if (ch[i] == 76 || ch[i] == 84 || ch[i] == 82 || ch[i] == 66)
		{
			if (continues)
			{
				tiles[x + y * width].AddRiver(ch[i]);
			}
			else if (creatingRoad)
			{
				tiles[x + y * width].AddRoad(ch[i]);
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
			tiles[x + y * width].AddType(std::stoi(tileType));
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
				if (!xSizeIsSet || !ySizeIsSet)
				{
					if (!xSizeIsSet)
						width = std::stoi(tileType);
					if (!ySizeIsSet)
						height = std::stoi(tileType);
				}
				else
				{
					tiles[x + y * width].AddType(std::stoi(tileType));
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
		for (int y = 0; y <= yMapSize; y += dimension)
		{
			for (int x = 0; x < xMapSize; x++)
			{
				gfx.PutPixel(x, y, color);
			}
		}
		for (int x = 0; x <= xMapSize; x += dimension)
		{
			for (int y = 0; y < yMapSize; y++)
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
	for (int x = 0; x * dimension < xMapSize; x++)
	{
		for (int y = 0; y * dimension < yMapSize; y++)
		{
			tiles[x + xOffset + y * width + yOffset * width].Draw(x * dimension, y * dimension, gfx);
		}
	}
}

void Map::MoveCharacter(Pos& dir)
{
	//Calculate center of the map, coordinates of visible area of the map and coordinates of map edge
	Pos futureCharacterPos = characterPos + dir;
	const int xMapCenter = int(xMapSize / dimension / 2);
	const int yMapCenter = int(yMapSize / dimension / 2);
	const int xVisibleArea = xMapSize + xOffset;
	const int yVisibleArea = yMapSize + yOffset;
	const int xMapEdge = width * dimension;
	const int yMapEdge = height * dimension;

	//Check if the half of the map character is on has a visible edge, if not, move the map
	//towards the edge instead of moving the character
	if (futureCharacterPos.x > xMapCenter && xVisibleArea < xMapEdge || futureCharacterPos.x < xMapCenter && xOffset * dimension > 0 || futureCharacterPos.y > yMapCenter && yVisibleArea < yMapEdge || futureCharacterPos.y < yMapCenter && yOffset * dimension > 0)
	{
		Move(dir);
	} 
	else
	{
		if (!(dir.x + characterPos.x < 0 || dir.x + characterPos.x >= width || dir.y + characterPos.y < 0 || dir.y + characterPos.y >= height))
		{
			if (tiles[dir.x + characterPos.x + (dir.y + characterPos.y) * width].IsPassable())
			{
				int timeSpent = 0;
				MoveCharacterOut(dir, timeSpent);
				MoveCharacterIn(dir, timeSpent);
				characterPos += dir;
				time.Add(timeSpent, 'm');
			}
		}
	}	
}

void Map::MoveCharacterOut(Pos& dir, int& timeSpent)
{
	//Check if there's river on the side character is going. If yes, then add +1H
	timeSpent += tiles[characterPos.x + characterPos.y * width].GetTimeCost() / 2 * 60;
	if (tiles[characterPos.x + characterPos.y * width].IsRiver(dir))
	{
		timeSpent += 60;
	}
	if (tiles[characterPos.x + characterPos.y * width].IsRoad(dir))
	{
		timeSpent -= 30;
	}
}

void Map::MoveCharacterIn(Pos & dir, int& timeSpent)
{
	timeSpent += tiles[dir.x + characterPos.x + (dir.y + characterPos.y) * width].GetTimeCost() / 2 * 60;
	
	//Check if there's river on the side character is coming from. If yes, then add +1H
	if (tiles[characterPos.x + characterPos.y * width].IsRiver(dir - dir * 2))
	{
		timeSpent += 60;
	}
	if (tiles[characterPos.x + characterPos.y * width].IsRoad(dir - dir * 2))
	{
		timeSpent -= 30;
	}
}

void Map::Move(Pos dir)
{
	xOffset += dir.x;
	yOffset += dir.y;
}

int Map::GetDimension() const
{
	return dimension;
}

Pos & Map::GetSize() const
{
	return Pos(xMapSize, yMapSize);
}

std::string Map::getTileType(const Pos & tilePos) const
{

	switch (tiles[characterPos.x + characterPos.y * width].GetType())
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
	case int(tileTypes::forest):
		texture = { basePath + "/Nature/Forest.bmp" };
		timeCost = 3;
		break;
	case int(tileTypes::mountain):
		texture = { basePath + "/Nature/Mountain.bmp" };
		passable = false;
		timeCost = 0;
		break;
	case int(tileTypes::swamp):
		texture = { basePath + "/Nature/Swamp.bmp" };
		timeCost = 6;
		break;
	case int(tileTypes::plains):
		texture = { basePath + "/Error/Error.bmp" };
		timeCost = 2;
		break;
	case int(tileTypes::villageSize1):
		texture = { basePath + "/Village/VillageSize1.bmp" };
		timeCost = 1;
		break;
	case int(tileTypes::villageSize2):
		texture = { basePath + "/Village/VillageSize2.bmp" };
		timeCost = 1;
		break;
	case int(tileTypes::villageSize3):
		texture = { basePath + "/Village/VillageSize3.bmp" };
		timeCost = 1;
		break;
	case int(tileTypes::field):
		texture = { basePath + "/Village/Field.bmp" };
		timeCost = 2;
		break;
	case int(tileTypes::road):
		texture = { basePath + "/Error/Error.bmp" };
		timeCost = 2;
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
	//Field is empty tile and road needs to be drawn separately because of the 4 directions road can go
	if (typeID != int(tileTypes::field) && typeID != int(tileTypes::road))
	{
		gfx.DrawSprite(x, y, texture, SpriteEffect::Chroma(Colors::Black));
	}

	 //If tile type is road, then draw it by the directions it goes
	if (typeID == int(tileTypes::road))
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

	//Draw out rivers
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

bool Map::Tile::IsRiver(Pos & dir) const
{
	if (dir.x == 1)
	{
		return riverRight;
	}
	if (dir.x == -1)
	{
		return riverLeft;
	}
	if (dir.y == 1)
	{
		return riverBottom;
	}
	if (dir.y == -1)
	{
		return riverTop;
	}
	assert(false);
	return false;
}

bool Map::Tile::IsRoad(Pos & dir) const
{
	if (dir.x == 1)
	{
		return roadRight;
	}
	if (dir.x == -1)
	{
		return roadLeft;
	}
	if (dir.y == 1)
	{
		return roadBottom;
	}
	if (dir.y == -1)
	{
		return roadTop;
	}
	assert(false);
	return false;
}
