#include "Board.h"
#include <assert.h>
#include "SpriteCodex.h"

Board::Board(Graphics & in_gfx, Vec2& in_characterPos)
	:
	gfx(in_gfx),
	characterPos(in_characterPos)
{
	LoadCustomMap();
}

void Board::Draw() const
{
	DrawBorder();
	DrawTileTextures();
	DrawTime();
	DrawCharacterInfo();
}

int Board::GetDimension() const
{
	return dimension;
}

bool Board::MoveCharacter(const Vec2 & dir)
{
	assert(abs(dir.x) + abs(dir.y) == 1);
	if (dir.x + characterPos.x < 0 || dir.x + characterPos.x >= mapWidth || dir.y + characterPos.y < 0 || dir.y + characterPos.y >= mapHeight)
	{
		return false;
	}
	else
	{
		int timeSpent = GetTimeCost(dir);
		if (timeSpent == -1)
		{
			return false;
		}
		if (time + timeSpent > 24)
		{
			time += timeSpent - 24;
		}
		else
		{
			time += timeSpent;
			angle += 10*timeSpent;
		}
		return true;
	}
}

void Board::DrawTime() const
{
	const int y = 5;
	const int x = Graphics::ScreenWidth - 55;
	SpriteCodex::DrawTextTime(x - 50, y-1, gfx);
	SpriteCodex::DrawTextH(x + 12, y, gfx);

	switch (int(time / 10))
	{
	case 2:
		SpriteCodex::DrawNumber2(x - 10, y, gfx);
		switch (time % 20)
		{
		case 0:
			SpriteCodex::DrawNumber0(x, y, gfx);
			break;
		case 1:
			SpriteCodex::DrawNumber1(x, y, gfx);
			break;
		case 2:
			SpriteCodex::DrawNumber2(x, y, gfx);
			break;
		case 3:
			SpriteCodex::DrawNumber3(x, y, gfx);
			break;
		case 4:
			SpriteCodex::DrawNumber4(x, y, gfx);
			break;
		}
		break;
	case 1:
		SpriteCodex::DrawNumber1(x - 10, y, gfx);
		switch (time % 10)
		{
		case 0:
			SpriteCodex::DrawNumber0(x, y, gfx);
			break;
		case 1:
			SpriteCodex::DrawNumber1(x, y, gfx);
			break;
		case 2:
			SpriteCodex::DrawNumber2(x, y, gfx);
			break;
		case 3:
			SpriteCodex::DrawNumber3(x, y, gfx);
			break;
		case 4:
			SpriteCodex::DrawNumber4(x, y, gfx);
			break;
		case 5:
			SpriteCodex::DrawNumber5(x, y, gfx);
			break;
		case 6:
			SpriteCodex::DrawNumber6(x, y, gfx);
			break;
		case 7:
			SpriteCodex::DrawNumber7(x, y, gfx);
			break;
		case 8:
			SpriteCodex::DrawNumber8(x, y, gfx);
			break;
		case 9:
			SpriteCodex::DrawNumber9(x, y, gfx);
			break;
		}
		break;
	case 0:
		SpriteCodex::DrawNumber0(x - 10, y, gfx);
		switch (time % 10)
		{
		case 0:
			SpriteCodex::DrawNumber0(x, y, gfx);
			break;
		case 1:
			SpriteCodex::DrawNumber1(x, y, gfx);
			break;
		case 2:
			SpriteCodex::DrawNumber2(x, y, gfx);
			break;
		case 3:
			SpriteCodex::DrawNumber3(x, y, gfx);
			break;
		case 4:
			SpriteCodex::DrawNumber4(x, y, gfx);
			break;
		case 5:
			SpriteCodex::DrawNumber5(x, y, gfx);
			break;
		case 6:
			SpriteCodex::DrawNumber6(x, y, gfx);
			break;
		case 7:
			SpriteCodex::DrawNumber7(x, y, gfx);
			break;
		case 8:
			SpriteCodex::DrawNumber8(x, y, gfx);
			break;
		case 9:
			SpriteCodex::DrawNumber9(x, y, gfx);
			break;
		}
		break;
	}
	SpriteCodex::DrawClock(x - 60, y + 30, gfx);
	gfx.DrawLine(x - 10, y + 80, 40, angle, Colors::White);
}

void Board::DrawBorder() const
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

void Board::DrawTileTextures() const
{
	int tileTypeID;
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			for (int k = 0; k < Tiles[i][j].propertyCount; k++)
			{
				tileTypeID = Tiles[i][j].properties[k];
				switch (tileTypeID)
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
				case 8:
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
				case 12:
					for (int y = dimension * j + 1; y < dimension * j + dimension; y++)
					{
						gfx.PutPixel(i * dimension, y, 0, 180, 255);
					}
					break;
				case 13:
					for (int x = dimension * i + 1; x < dimension * i + dimension; x++)
					{
						gfx.PutPixel(x, j* dimension, 0, 180, 255);
					}
					break;
				case 14:
					for (int y = dimension * j + 1; y < dimension * j + dimension; y++)
					{
						gfx.PutPixel(i * dimension + dimension, y, 0, 180, 255);
					}
					break;
				case 15:
					for (int x = dimension * i + 1; x < dimension * i + dimension; x++)
					{
						gfx.PutPixel(x, j* dimension + dimension, 0, 180, 255);
					}
					break;
				case 16:
					SpriteCodex::DrawField(dimension * i, dimension * j, gfx);
					break;
				default:
					assert(false);
					break;
				}
			}
		}
	}
}

int Board::GetTimeCost(const Vec2& dir) const
{
	int timeSpent = 0;
	int tileTypeID;
	for (int i = 0; i < Tiles[int(characterPos.x)][int(characterPos.y)].propertyCount; i++)
	{
		tileTypeID = Tiles[int(characterPos.x)][int(characterPos.y)].properties[i];
		switch (tileTypeID)
		{
		case 12:
			if (dir.x == -1)
			{
				timeSpent += 1;
			}
			break;
		case 13:
			if (dir.y == -1)
			{
				timeSpent += 1;
			}
			break;
		case 14:
			if (dir.x == 1)
			{
				timeSpent += 1;
			}
			break;
		case 15:
			if (dir.y == 1)
			{
				timeSpent += 1;
			}
			break;
		}
	}
	int i = 0;
	while (i < Tiles[int(characterPos.x + dir.x)][int(characterPos.y + dir.y)].propertyCount && timeSpent >= 0)
	{
		tileTypeID = Tiles[int(characterPos.x + dir.x)][int(characterPos.y + dir.y)].properties[i];
		switch (tileTypeID)
		{
		case 1:
			timeSpent += 3;
			break;
		case 2:
			timeSpent = -1;
			break;
		case 3:
			timeSpent += 6;
			break;
		case 4:
			timeSpent += 1;
			break;
		case 5:
			timeSpent += 1;
			break;
		case 6:
			timeSpent += 1;
			break;
		case 7:
			timeSpent += 1;
			break;
		case 8:
			timeSpent += 2;
			break;
		case 9:
			timeSpent += 1;
			break;
		case 10:
			timeSpent += 1;
			break;
		case 11:
			timeSpent += 1;
			break;
		case 12:
			if (dir.x == 1)
			{
				timeSpent += 1;
			}
			break;
		case 13:
			if (dir.y == 1)
			{
				timeSpent += 1;
			}
			break;
		case 14:
			if (dir.x == -1)
			{
				timeSpent += 1;
			}
			break;
		case 15:
			if (dir.y == -1)
			{
				timeSpent += 1;
			}
			break;
		case 16:
			timeSpent += 2;
			break;
		default:
			assert(false);
		}
		i++;
	}
	return timeSpent;
}

void Board::LoadCustomMap()
{
	for (int i = 0; i < mapWidth; i++)
	{
		for (int j = 0; j < mapHeight; j++)
		{
			Tiles[i][j].AddProperty(8);
		}
	}
	Tiles[1][0].AddProperty(1, true);
	Tiles[1][1].AddProperty(2, true);
	Tiles[1][2].AddProperty(3, true);
	Tiles[1][3].AddProperty(4, true);
	Tiles[1][4].AddProperty(5, true);
	Tiles[1][5].AddProperty(6, true);
	Tiles[1][6].AddProperty(7, true);
	Tiles[1][7].AddProperty(8, true);
	Tiles[1][8].AddProperty(9, true);
	Tiles[1][9].AddProperty(10, true);
	Tiles[1][10].AddProperty(11, true);
	Tiles[1][11].AddProperty(12, true);
	Tiles[1][12].AddProperty(13, true);
	Tiles[1][13].AddProperty(14, true);
	Tiles[1][14].AddProperty(15, true);
	Tiles[2][0].AddProperty(16, true);
	Tiles[2][13].AddProperty(15, true);
	Tiles[2][14].AddProperty(13, true);
}

void Board::DrawCharacterInfo() const
{
	int x = 20;
	int y = 5;
	SpriteCodex::DrawTextX(mapWidth * dimension + x, 5, gfx);
	SpriteCodex::DrawTextColon(mapWidth * dimension + x + 10, y, gfx);
	assert(int(characterPos.x / 10) < 2);
	if (int((characterPos.x + 1) / 10) == 1)
	{
		SpriteCodex::DrawNumber1(mapWidth * dimension + x + 17, y, gfx);
	}
	else
	{
		SpriteCodex::DrawNumber0(mapWidth * dimension + x + 17, y, gfx);
	}
	switch (int(characterPos.x + 1) % 10)
	{
		case 0:
			SpriteCodex::DrawNumber0(mapWidth * dimension + x + 27, y, gfx);
			break;
		case 1:
			SpriteCodex::DrawNumber1(mapWidth * dimension + x + 27, y, gfx);
			break;
		case 2:
			SpriteCodex::DrawNumber2(mapWidth * dimension + x + 27, y, gfx);
			break;
		case 3:
			SpriteCodex::DrawNumber3(mapWidth * dimension + x + 27, y, gfx);
			break;
		case 4:
			SpriteCodex::DrawNumber4(mapWidth * dimension + x + 27, y, gfx);
			break;
		case 5:
			SpriteCodex::DrawNumber5(mapWidth * dimension + x + 27, y, gfx);
			break;
		case 6:
			SpriteCodex::DrawNumber6(mapWidth * dimension + x + 27, y, gfx);
			break;
		case 7:
			SpriteCodex::DrawNumber7(mapWidth * dimension + x + 27, y, gfx);
			break;
		case 8:
			SpriteCodex::DrawNumber8(mapWidth * dimension + x + 27, y, gfx);
			break;
		case 9:
			SpriteCodex::DrawNumber9(mapWidth * dimension + x + 27, y, gfx);
			break;
	}
	SpriteCodex::DrawTextY(mapWidth * dimension + x, y + 15, gfx);
	SpriteCodex::DrawTextColon(mapWidth * dimension + x + 10, y + 15, gfx);
	assert(int(characterPos.y / 10) < 2);
	if (int((characterPos.y + 1)/ 10) == 1)
	{
		SpriteCodex::DrawNumber1(mapWidth * dimension + x + 17, y + 15, gfx);
	}
	else
	{
		SpriteCodex::DrawNumber0(mapWidth * dimension + x + 17, y + 15, gfx);
	}
	switch (int(characterPos.y + 1) % 10)
	{
	case 0:
		SpriteCodex::DrawNumber0(mapWidth * dimension + x + 27, y + 15, gfx);
		break;
	case 1:
		SpriteCodex::DrawNumber1(mapWidth * dimension + x + 27, y + 15, gfx);
		break;
	case 2:
		SpriteCodex::DrawNumber2(mapWidth * dimension + x + 27, y + 15, gfx);
		break;
	case 3:
		SpriteCodex::DrawNumber3(mapWidth * dimension + x + 27, y + 15, gfx);
		break;
	case 4:
		SpriteCodex::DrawNumber4(mapWidth * dimension + x + 27, y + 15, gfx);
		break;
	case 5:
		SpriteCodex::DrawNumber5(mapWidth * dimension + x + 27, y + 15, gfx);
		break;
	case 6:
		SpriteCodex::DrawNumber6(mapWidth * dimension + x + 27, y + 15, gfx);
		break;
	case 7:
		SpriteCodex::DrawNumber7(mapWidth * dimension + x + 27, y + 15, gfx);
		break;
	case 8:
		SpriteCodex::DrawNumber8(mapWidth * dimension + x + 27, y + 15, gfx);
		break;
	case 9:
		SpriteCodex::DrawNumber9(mapWidth * dimension + x + 27, y + 15, gfx);
		break;
	}
}

Board::Tile::Tile()
{
	for (int i = 1; i < Tile::nTypes; i++)
	{
		properties[i] = 0;
	}

	Main.insert(1);
	Main.insert(2);
	Main.insert(3);
	Main.insert(4);
	Main.insert(5);
	Main.insert(6);
	Main.insert(7);
	Main.insert(8);
	Main.insert(9);
	Main.insert(10);
	Main.insert(16);

	Sides.insert(12);
	Sides.insert(13);
	Sides.insert(14);
	Sides.insert(15);

	assert(nTypes == 16);
}

void Board::Tile::AddProperty(int propertyID, bool replace)
{
	bool canBeAdded = true;
	bool mainFound = false;
	int loc = 0;

	for (int i = 0; i < propertyCount; i++)
	{
		if (Main.count(properties[i]) == 1)
		{
			loc = i;
			mainFound = true;
			break;
		}
	}

	if (mainFound)
	{
		if (Sides.count(propertyID) != 1)
		{
			canBeAdded = false;
		}

		int i = 0;
		while (i < propertyCount && canBeAdded)
		{
			if (propertyID == properties[i])
			{
				canBeAdded = false;
				replace = false;
			}
			i++;
		}
	}

	if (canBeAdded)
	{
		properties[propertyCount] = propertyID;
		propertyCount++;
	}
	else
	{
		if (replace)
		{
			properties[loc] = propertyID;
		}
	}
}

void Board::Tile::RemoveProperty(int propertyID)
{
	bool found = false;
	int foundLoc;
	for (int i = 0; i < propertyCount; i++)
	{
		if (properties[i] == propertyID)
		{
			found = true;
			foundLoc = i;
			break;
		}
	}

	assert(found);

	if (found)
	{
		for (int i = foundLoc; i < propertyCount; i++)
		{
			properties[i] = properties[i + 1];
		}

		propertyCount--;
	}
}

/*
Default: River can be added

0 = Map Border - Unaccessable, nothing can be added
1 = Forest - 3H
2 = Mountain - Unaccessable, nothing can be addedd
3 = Swamp - 6H
4 = LeftRoad - 1H
5 = TopRoad - 1H
6 = RightRoad - 1H
7 = BottomRoad - 1H
8 = Plains - 2H
9 = Village Size 1 - 1H
10 = Village Size 2 - 1H
11 = Village Size 3 - 1H
12 = LeftRiver - 2H
13 = TopRiver - 2H
14 = RightRiver - 2H
15 = BottomRiver - 2H
16 = Field = 2H
*/