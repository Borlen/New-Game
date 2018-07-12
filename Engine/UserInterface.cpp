#include "UserInterface.h"
/*
void UserInterface::DrawTime() const
{
	const int y = 5;
	const int x = Graphics::ScreenWidth - 55;
	SpriteCodex::DrawTextTime(x - 50, y - 1, gfx);
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
	SpriteCodex::DrawClock(x - 42, y + 20, gfx);
	gfx.DrawLine(x - 14, y + 50, 15, angle - 90, Colors::White);
}

void UserInterface::DrawCharacterInfo() const
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
	if (int((characterPos.y + 1) / 10) == 1)
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

bool Board::CharacterIsOnRoad() const
{
	for (int i = 0; i < Tiles[int(characterPos.x)][int(characterPos.y)].propertyCount; i++)
	{
		int tileType = Tiles[int(characterPos.x)][int(characterPos.y)].properties[i];
		if (tileType == 4 || tileType == 5 || tileType == 6 || tileType == 7)
		{
			return true;
		}
	}
	return false;
}

bool UserInterface::MoveCharacter(const Pos & dir)
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
			angle += 30 * timeSpent;
		}
		else
		{
			time += timeSpent;
			angle += 30 * timeSpent;
		}
		if (angle + 30 * timeSpent > 360)
		{
			angle -= 360;
		}
		return true;
	}
}
*/
