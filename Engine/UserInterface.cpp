#include "UserInterface.h"
#include "SpriteCodex.h"
#include <assert.h>

UserInterface::UserInterface(Time& in_time, Character& in_player, Map& in_map, Graphics& in_gfx)
	:
	time(in_time),
	player(in_player),
	map(in_map),
	gfx(in_gfx)
{
}


void UserInterface::DrawTime() const
{
	const int y = 5;
	const int x = Graphics::ScreenWidth - 55;
	SpriteCodex::DrawTextTime(x - 50, y - 1, gfx);
	SpriteCodex::DrawTextH(x + 12, y, gfx);

	switch (int(time.Get('h') / 10))
	{
	case 2:
		SpriteCodex::DrawNumber2(x - 10, y, gfx);
		switch (int(time.Get('h')) % 20)
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
		switch (int(time.Get('h')) % 10)
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
		switch (int(time.Get('h')) % 10)
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
	gfx.DrawLine(x - 14, y + 50, 15, (int(time.Get('h')) % 12) * 30 - 90, Colors::White);
}
void UserInterface::DrawCharacterInfo() const
{
	int mapWidth = map.GetWidth();
	int mapHeight = map.GetHeight();
	int mapDimension = map.GetDimension();
	Pos& characterPos = player.GetPos();
	int x = 20;
	int y = 5;
	SpriteCodex::DrawTextX(mapWidth * mapDimension + x, 5, gfx);
	SpriteCodex::DrawTextColon(mapWidth * mapDimension + x + 10, y, gfx);
	assert(int(characterPos.x / 10) < 2);
	if (int((characterPos.x + 1) / 10) == 1)
	{
		SpriteCodex::DrawNumber1(mapWidth * mapDimension + x + 17, y, gfx);
	}
	else
	{
		SpriteCodex::DrawNumber0(mapWidth * mapDimension + x + 17, y, gfx);
	}
	switch (int(characterPos.x + 1) % 10)
	{
	case 0:
		SpriteCodex::DrawNumber0(mapWidth * mapDimension + x + 27, y, gfx);
		break;
	case 1:
		SpriteCodex::DrawNumber1(mapWidth * mapDimension + x + 27, y, gfx);
		break;
	case 2:
		SpriteCodex::DrawNumber2(mapWidth * mapDimension + x + 27, y, gfx);
		break;
	case 3:
		SpriteCodex::DrawNumber3(mapWidth * mapDimension + x + 27, y, gfx);
		break;
	case 4:
		SpriteCodex::DrawNumber4(mapWidth * mapDimension + x + 27, y, gfx);
		break;
	case 5:
		SpriteCodex::DrawNumber5(mapWidth * mapDimension + x + 27, y, gfx);
		break;
	case 6:
		SpriteCodex::DrawNumber6(mapWidth * mapDimension + x + 27, y, gfx);
		break;
	case 7:
		SpriteCodex::DrawNumber7(mapWidth * mapDimension + x + 27, y, gfx);
		break;
	case 8:
		SpriteCodex::DrawNumber8(mapWidth * mapDimension + x + 27, y, gfx);
		break;
	case 9:
		SpriteCodex::DrawNumber9(mapWidth * mapDimension + x + 27, y, gfx);
		break;
	}
	SpriteCodex::DrawTextY(mapWidth * mapDimension + x, y + 15, gfx);
	SpriteCodex::DrawTextColon(mapWidth * mapDimension + x + 10, y + 15, gfx);
	assert(int(characterPos.y / 10) < 2);
	if (int((characterPos.y + 1) / 10) == 1)
	{
		SpriteCodex::DrawNumber1(mapWidth * mapDimension + x + 17, y + 15, gfx);
	}
	else
	{
		SpriteCodex::DrawNumber0(mapWidth * mapDimension + x + 17, y + 15, gfx);
	}
	switch (int(characterPos.y + 1) % 10)
	{
	case 0:
		SpriteCodex::DrawNumber0(mapWidth * mapDimension + x + 27, y + 15, gfx);
		break;
	case 1:
		SpriteCodex::DrawNumber1(mapWidth * mapDimension + x + 27, y + 15, gfx);
		break;
	case 2:
		SpriteCodex::DrawNumber2(mapWidth * mapDimension + x + 27, y + 15, gfx);
		break;
	case 3:
		SpriteCodex::DrawNumber3(mapWidth * mapDimension + x + 27, y + 15, gfx);
		break;
	case 4:
		SpriteCodex::DrawNumber4(mapWidth * mapDimension + x + 27, y + 15, gfx);
		break;
	case 5:
		SpriteCodex::DrawNumber5(mapWidth * mapDimension + x + 27, y + 15, gfx);
		break;
	case 6:
		SpriteCodex::DrawNumber6(mapWidth * mapDimension + x + 27, y + 15, gfx);
		break;
	case 7:
		SpriteCodex::DrawNumber7(mapWidth * mapDimension + x + 27, y + 15, gfx);
		break;
	case 8:
		SpriteCodex::DrawNumber8(mapWidth * mapDimension + x + 27, y + 15, gfx);
		break;
	case 9:
		SpriteCodex::DrawNumber9(mapWidth * mapDimension + x + 27, y + 15, gfx);
		break;
	}
}
/*
void UserInterface::DrawCharacterInfo() const
{
	
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