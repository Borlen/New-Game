#include "Board.h"
#include <assert.h>
#include "SpriteCodex.h"

Board::Board(Graphics & in_gfx)
	:
	gfx(in_gfx)
{
	for (int i = 0; i < mapWidth; i++)
	{
		for (int j = 0; j < mapHeight; j++)
		{
			Tiles[i][j].properties[0] = 8;
		}
	}
	Tiles[1][0].properties[0] = 1;
	Tiles[1][1].properties[0] = 2;
	Tiles[1][2].properties[0] = 3;
	Tiles[1][3].properties[0] = 4;
	Tiles[1][4].properties[0] = 5;
	Tiles[1][5].properties[0] = 6;
	Tiles[1][6].properties[0] = 7;
	Tiles[1][7].properties[0] = 8;
	Tiles[1][8].properties[0] = 9;
	Tiles[1][9].properties[0] = 10;
	Tiles[1][10].properties[0] = 11;
	Tiles[1][11].properties[0] = 12;
	Tiles[1][12].properties[0] = 13;
	Tiles[1][13].properties[0] = 14;
	Tiles[1][14].properties[0] = 15;
}

void Board::Draw() const
{
	DrawBorder();
	DrawTileTextures();
	DrawTime();
}

int Board::GetDimension() const
{
	return dimension;
}

int Board::GetTileType(const Vec2& moveTo) const
{
	if (moveTo.x < 0 || moveTo.y < 0 || moveTo.x > mapWidth || moveTo.y > mapHeight)
	{
		return 0;
	}
	if (Tiles[int(moveTo.x)][int(moveTo.y)].properties[0] > 0 && Tiles[int(moveTo.x)][int(moveTo.y)].properties[0] < 12)
	{
		return Tiles[int(moveTo.x)][int(moveTo.y)].properties[0];
	}
	else
	{
		return 8;
	}
}

bool Board::MoveCharacter(const Vec2 & dir, const Vec2& characterPos)
{
	assert(abs(dir.x) + abs(dir.y) == 1);

	int timeSpent;
	bool canGo = true;

	if (dir.x + characterPos.x < 0 || dir.x + characterPos.x > mapWidth || dir.y + characterPos.y < 0 || dir.y + characterPos.y > mapHeight)
	{
		return false;
	}

	switch (Tiles[int(dir.x + characterPos.x)][int(dir.y + characterPos.y)].properties[0])
	{
	case 1:
		timeSpent = 3;
		break;
	case 2:
		canGo = false;
		break;
	case 3:
		timeSpent = 6;
		break;
	case 4:
		timeSpent = 1;
		break;
	case 5:
		timeSpent = 1;
		break;
	case 6:
		timeSpent = 1;
		break;
	case 7:
		timeSpent = 1;
		break;
	case 8:
		timeSpent = 2;
		break;
	case 9:
		timeSpent = 1;
		break;
	case 10:
		timeSpent = 1;
		break;
	case 11:
		timeSpent = 1;
		break;
	case 12:
		timeSpent = 2;
		break;
	case 13:
		timeSpent = 2;
		break;
	case 14:
		timeSpent = 2;
		break;
	case 15:
		timeSpent = 2;
		break;
	}
	if (canGo)
	{
		if (time + timeSpent > 24)
		{
			time += timeSpent - 24;
		}
		else
		{
			time += timeSpent;
		}
	}
	return canGo;
}

void Board::DrawTime() const
{
	SpriteCodex::DrawTextTime(Graphics::ScreenWidth - 80, 19, gfx);
	SpriteCodex::DrawTextH(Graphics::ScreenWidth - 18, 20, gfx);
	switch (int(time / 10))
	{
	case 2:
		SpriteCodex::DrawNumber2(Graphics::ScreenWidth - 40, 20, gfx);
		switch (time % 20)
		{
		case 0:
			SpriteCodex::DrawNumber0(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 1:
			SpriteCodex::DrawNumber1(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 2:
			SpriteCodex::DrawNumber2(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 3:
			SpriteCodex::DrawNumber3(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 4:
			SpriteCodex::DrawNumber4(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		}
		break;
	case 1:
		SpriteCodex::DrawNumber1(Graphics::ScreenWidth - 40, 20, gfx);
		switch (time % 10)
		{
		case 0:
			SpriteCodex::DrawNumber0(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 1:
			SpriteCodex::DrawNumber1(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 2:
			SpriteCodex::DrawNumber2(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 3:
			SpriteCodex::DrawNumber3(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 4:
			SpriteCodex::DrawNumber4(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 5:
			SpriteCodex::DrawNumber5(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 6:
			SpriteCodex::DrawNumber6(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 7:
			SpriteCodex::DrawNumber7(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 8:
			SpriteCodex::DrawNumber8(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 9:
			SpriteCodex::DrawNumber9(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		}
		break;
	case 0:
		SpriteCodex::DrawNumber0(Graphics::ScreenWidth - 40, 20, gfx);
		switch (time % 10)
		{
		case 0:
			SpriteCodex::DrawNumber0(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 1:
			SpriteCodex::DrawNumber1(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 2:
			SpriteCodex::DrawNumber2(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 3:
			SpriteCodex::DrawNumber3(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 4:
			SpriteCodex::DrawNumber4(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 5:
			SpriteCodex::DrawNumber5(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 6:
			SpriteCodex::DrawNumber6(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 7:
			SpriteCodex::DrawNumber7(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 8:
			SpriteCodex::DrawNumber8(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		case 9:
			SpriteCodex::DrawNumber9(Graphics::ScreenWidth - 30, 20, gfx);
			break;
		}
		break;
	}
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
			}
		}
	}
}


/*
0 = Map Border - Unaccessable
1 = Forest - 3H
2 = Mountain - Unaccessable
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