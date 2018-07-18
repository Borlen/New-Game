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
	bool firstRun = true;

	//Iterate until the file runs out of chars
	int i = 0;
	while (i < ch.length())
	{
		//If it's the first iteration, set the xSize a ySize and move the i behind the numbers determining map size
		if (firstRun)
		{
			//set x size of the map
			std::string xSize;
			xSize = ch[i];
			int j = 1;
			while (ch[i + j] >= '0' && ch[i + j] <= '9')
			{
				xSize += ch[i + j];
				j++;
			}
			width = std::stoi(xSize);

			//set y size of the map
			std::string ySize;
			ySize = ch[i + j + 1];
			j += 2;
			while (ch[i + j] >= '0' && ch[i + j] <= '9')
			{
				ySize += ch[i + j];
				j++;
			}
			height = std::stoi(ySize);
			i += j;
			firstRun = false;
		}

		//If beginning of coordinates was found, start iterating through, geting x, y and tileType + road/river sides
		if (ch[i] == '[')
		{
			//iterate until the beginning of the next number (x coordinate) is found
			int j = 0;
			while (!(ch[i + j] >= '0' && ch[i + j] <= '9') && i + j < ch.length())
			{
				j++;
			}

			//iterate until the end of number and save that as x coordinate
			std::string xCoords;
			xCoords = ch[i + j];
			j++;
			while (ch[i + j] >= '0' && ch[i + j] <= '9')
			{
				xCoords += ch[i + j];
				j++;
			}
			int xCoordsNum = std::stoi(xCoords);

			//iterate until the beginning of the next number (y coordinate) is found
			while (!(ch[i + j] >= '0' && ch[i + j] <= '9') && i + j < ch.length())
			{
				j++;
			}

			//iterate until the end of the number and save that as x coordinate
			std::string yCoords;
			yCoords = ch[i + j];
			j++;
			while (ch[i + j] >= '0' && ch[i + j] <= '9')
			{
				yCoords = ch[i + j];
				j++;
			}
			int yCoordsNum = std::stoi(yCoords);

			//iterate until the beginning of the next number (tile type) is found or end of the file is reached
			while (!(ch[i + j] >= '0' && ch[i + j] <= '9') && i + j < ch.length())
			{
				j++;
			}

			//iterate until the end of number and save that as tile type
			std::string tileType;
			tileType = ch[i + j ];
			j++;
			while (ch[i + j] >= '0' && ch[i + j] <= '9')
			{
				tileType = ch[i + j];
				j++;
			}
			int tileTypeNum = std::stoi(tileType);
			
			//If tile type is of type road, then iterate until the end of road side setting chars
			if (tileTypeNum == 8)
			{
				while ((ch[i + j] == 'L' || ch[i + j] == 'T' || ch[i + j] == 'R' || ch[i + j] == 'B') && i + j < ch.length())
				{
					tiles[xCoordsNum + yCoordsNum * width].AddRoad(ch[i + j]);
					j++;
				}
			}

			//Iterate until the end of river side setting chars
			j++;
			while ((ch[i + j] == 'L' || ch[i + j] == 'T' || ch[i + j] == 'R' || ch[i + j] == 'B') && i + j < ch.length())
			{
				tiles[xCoordsNum + yCoordsNum * width].AddRiver(ch[i + j]);
				j++;
			}

			//Add the tile type to the tile and move the i to the end of the line
			tiles[xCoordsNum + yCoordsNum * width].AddType(tileTypeNum);
			i += j;
		}
		else
		{
			//If it's not the first iteration and the char signaling beginning of coordinates ('[') was not found, move to the next char
			i++;
		}
	}
	//If the x/y size of map is smaller than width/height * dimension, then change the values
	if (width * dimension < xSize)
	{
		xSize = width*dimension;
	}
	if (height * dimension < ySize)
	{
		ySize = height*dimension;
	}
}

void Map::Draw()
{
	DrawGrid();
	DrawTileTextures();
}

void Map::DrawGrid() const
{
	{
		//Extra width added to the edge of the grid if it's representing edge of the map
		bool visibleLeftEdge = false;
		bool visibleTopEdge = false;
		bool visibleRightEdge = false;
		bool visibleBotEdge = false;

		//Determine which edges of the map are visible
		if (xOffset == 0)
		{
			visibleLeftEdge = true;
		}
		if (yOffset == 0)
		{
			visibleTopEdge = true;
		}
		if (xOffset * dimension + xSize >= width * dimension)
		{
			visibleRightEdge = true;
		}

		if (yOffset * dimension + ySize >= height * dimension)
		{
			visibleBotEdge = true;
		}

		//If map edge is visible, draw out 3 px strong border on that side, else 1px
		if (visibleLeftEdge)
		{
			for (int x = 0; x <= extraEdgeWidth - 1; x ++)
			{
				for (int y = extraEdgeWidth; y <= ySize + extraEdgeWidth; y++)
				{
					gfx.PutPixel(x, y, gridColor);
				}
			}
		}

		if (visibleTopEdge)
		{
			for (int y = 0; y <= extraEdgeWidth - 1; y++)
			{
				for (int x = extraEdgeWidth; x <= xSize + extraEdgeWidth; x++)
				{
					gfx.PutPixel(x, y, gridColor);
				}
			}
		}

		if (visibleRightEdge)
		{
			for (int x = xSize + extraEdgeWidth; x <= xSize + 2 * extraEdgeWidth; x++)
			{
				for (int y = extraEdgeWidth; y <= ySize + extraEdgeWidth; y++)
				{
					gfx.PutPixel(x, y, gridColor);
				}
			}
		}

		if (visibleBotEdge)
		{
			for (int y = ySize + extraEdgeWidth; y <= ySize + 2 * extraEdgeWidth; y++)
			{
				for (int x = extraEdgeWidth; x <= xSize + extraEdgeWidth; x++)
				{
					gfx.PutPixel(x, y, gridColor);
				}
			}
		}

		//Fill up the holes between the expanded edges
		if (visibleLeftEdge && visibleTopEdge)
		{
			for (int x = 0; x < extraEdgeWidth; x++)
			{
				for (int y = 0; y < extraEdgeWidth; y++)
				{
					gfx.PutPixel(x, y, gridColor);
				}
			}
		}
		if (visibleTopEdge && visibleRightEdge)
		{
			for (int x = xSize + extraEdgeWidth; x <= xSize + 2 * extraEdgeWidth; x++)
			{
				for (int y = 0; y < extraEdgeWidth; y++)
				{
					gfx.PutPixel(x, y, gridColor);
				}
			}
		}
		if (visibleRightEdge && visibleBotEdge)
		{
			for (int x = xSize + extraEdgeWidth; x <= xSize + 2 * extraEdgeWidth; x++)
			{
				for (int y = ySize + extraEdgeWidth; y <= ySize + 2 * extraEdgeWidth; y++)
				{
					gfx.PutPixel(x, y, gridColor);
				}
			}
		}
		if (visibleBotEdge && visibleLeftEdge)
		{
			for (int x = 0; x < extraEdgeWidth; x++)
			{
				for (int y = ySize + extraEdgeWidth; y <= ySize + 2 * extraEdgeWidth; y++)
				{
					gfx.PutPixel(x, y, gridColor);
				}
			}
		}


		//Draw grid
		for (int y = extraEdgeWidth; y <= ySize + extraEdgeWidth; y += dimension)
		{
			for (int x = extraEdgeWidth; x <= xSize + extraEdgeWidth; x++)
			{
				gfx.PutPixel(x, y, gridColor);
			}
		}
		for (int x = extraEdgeWidth; x <= xSize + extraEdgeWidth; x += dimension)
		{
			for (int y = extraEdgeWidth; y <= ySize + extraEdgeWidth; y++)
			{
				gfx.PutPixel(x, y, gridColor);
			}
		}
	}
}

void Map::DrawTileTextures() const
{
	for (int x = 0; x * dimension < xSize; x++)
	{
		for (int y = 0; y * dimension < ySize; y++)
		{
			tiles[x + xOffset + (y + yOffset) * width].Draw(x * dimension, y * dimension, gfx);
		}
	}
}

bool Map::MoveCharacter(Pos& dir)
{
	//Calculate center of the map, coordinates of visible area of the map and coordinates of map edge
	Pos futureCharacterPos = characterPos + dir;
	const int xVisibleArea = xSize + xOffset * dimension;
	const int yVisibleArea = ySize + yOffset * dimension;
	const int xMapEdge = width * dimension;
	const int yMapEdge = height * dimension;

	//Check if the half of the map character is on has a visible edge, if not, move the map
	//towards the edge instead of moving the character
	if ((futureCharacterPos.x - xOffset) * 2 * dimension > xSize && xVisibleArea < xMapEdge || (futureCharacterPos.x - xOffset) * 2 * dimension < xSize && xOffset * dimension > 0 || (futureCharacterPos.y - yOffset) * dimension * 2 > ySize && yVisibleArea < yMapEdge || (futureCharacterPos.y - yOffset) * dimension * 2 < ySize && yOffset * dimension > 0)
	{
		if (tiles[futureCharacterPos.x + futureCharacterPos.y * width].IsPassable())
		{
			Move(dir);
			int timeSpent = 0;
			MoveCharacterOut(dir, timeSpent);
			MoveCharacterIn(dir, timeSpent);
			time.Add(timeSpent, 'm');
			return true;
		}
		return false;
	} 
	else
	{
		if (!(dir.x + characterPos.x < 0 || (dir.x + characterPos.x) * dimension >= xSize + xOffset * dimension || dir.y + characterPos.y < 0 || (dir.y + characterPos.y) * dimension >= ySize + yOffset * dimension))
		{
			if (tiles[futureCharacterPos.x + futureCharacterPos.y * width].IsPassable())
			{
				int timeSpent = 0;
				MoveCharacterOut(dir, timeSpent);
				MoveCharacterIn(dir, timeSpent);
				time.Add(timeSpent, 'm');
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
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
	if (tiles[dir.x + characterPos.x + dir.y + characterPos.y * width].IsRiver(dir - dir * 2))
	{
		timeSpent += 60;
	}
	if (tiles[dir.x + characterPos.x + dir.y + characterPos.y * width].IsRoad(dir - dir * 2))
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

Pos Map::GetSize() const
{
	return Pos(xSize, ySize);
}

Pos Map::GetOffset() const
{
	return Pos(xOffset,yOffset);
}

int Map::GetMargin() const
{
	return extraEdgeWidth;
}

std::string Map::GetTileType(const Pos & tilePos) const
{

	switch (tiles[tilePos.x + tilePos.y * width].GetType())
	{
	case 0:
		return ("Forest");
		break;
	case 1:
		return ("Mountain");
		break;
	case 2:
		return ("Swamp");
		break;
	case 3:
		return ("Plains");
		break;
	case 4:
		return ("Village");
		break;
	case 5:
		return ("Village");
		break;
	case 6:
		return ("Village");
		break;
	case 7:
		return ("Field");
		break;
	case 8:
		return ("Road");
		break;
	default:
		assert(false);
		return ("Error");
	}
}

Map::Tile::Tile()
{
	AddType(3);
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
	if (typeID != int(tileTypes::plains) && typeID != int(tileTypes::road))
	{
		gfx.DrawSprite(x + extraEdgeWidth, y + extraEdgeWidth, texture, SpriteEffect::Chroma(Colors::Black));
	}

	 //If tile type is road, then draw it by the directions it goes
	if (typeID == int(tileTypes::road))
	{
		if (roadLeft)
		{
			gfx.DrawSprite(x + extraEdgeWidth, y, { basePath + "/Road/LeftRoad.bmp" }, SpriteEffect::Chroma(Colors::Black));
		}
		if (roadTop)
		{
			gfx.DrawSprite(x + extraEdgeWidth, y, { basePath + "/Road/TopRoad.bmp" }, SpriteEffect::Chroma(Colors::Black));
		}
		if (roadRight)
		{
			gfx.DrawSprite(x + extraEdgeWidth, y, { basePath + "/Road/RightRoad.bmp" }, SpriteEffect::Chroma(Colors::Black));
		}
		if (roadBottom)
		{
			gfx.DrawSprite(x + extraEdgeWidth, y, { basePath + "/Road/LeftRoad.bmp" }, SpriteEffect::Chroma(Colors::Black));
		}
	}

	//Draw out rivers
	if (riverLeft)
	{
		for (int i = y + 1; i < y + dimension; i++)
		{
			gfx.PutPixel(x + extraEdgeWidth, i + extraEdgeWidth, 0, 180, 255);
		}
	}
	if (riverTop)
	{
		for (int i = x + 1; i < x + dimension; i++)
		{
			gfx.PutPixel(i + extraEdgeWidth, y + extraEdgeWidth, 0, 180, 255);
		}
	}
	if (riverRight)
	{
		for (int i = y + 1; i < y + dimension; i++)
		{
			gfx.PutPixel(x + dimension + extraEdgeWidth, i + extraEdgeWidth, 0, 180, 255);
		}
	}
	if (riverBottom)
	{
		for (int i = x + 1; i < x + dimension; i++)
		{
			gfx.PutPixel(i + extraEdgeWidth, y + dimension + extraEdgeWidth, 0, 180, 255);
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
