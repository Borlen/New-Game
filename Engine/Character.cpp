#include "Character.h"
#include <assert.h>
#include "SpriteCodex.h"


Character::Character(Vec2& in_mapSize)
		:
	mapSize(in_mapSize)
{
}

void Character::Draw(Graphics & gfx, int dimension) const
{
	for (int i = int(dimension/6); i < int(dimension - dimension/6) + 1; i++)
	{
			gfx.PutPixel(i + int(dimension * pos.x), i + int(dimension * pos.y), color);
		
	}
	for (int i = int(dimension - dimension / 6); i > int(dimension / 6) - 1; i--)
	{
		gfx.PutPixel(i + int(dimension * pos.x), int(dimension * pos.y + dimension - i), color);
	}
}

void Character::Move(const Vec2& dir, int idTileType)
{
	assert(abs(dir.x) + abs(dir.y) == 1);

	int timeSpent;
	bool canGo = true;

	switch (idTileType)
	{
		case 0:
			canGo = false;
			break;
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

		pos += dir;
	}
}

void Character::DrawTime(Graphics & gfx) const
{
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

Vec2 & Character::GetPos()
{
	return pos;
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
8 = Field - 2A
9 = Village Size 1 - 1H
10 = Village Size 2 - 1H
11 = Village Size 3 - 1H
*/