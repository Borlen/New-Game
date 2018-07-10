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

	int apCost;
	bool canGo = true;

	switch (idTileType)
	{
		case 0:
			canGo = false;
			break;
		case 1:
			apCost = 1;
			break;
		case 2:
			apCost = 2;
			break;
		case 3: 
			apCost = 3;
			break;
		case 4:
			apCost = 4;
			break;
		case 5:
			canGo = false;
			break;
	}
	if (canGo && actionPoints - apCost >= 0)
	{
		pos += dir;
		actionPoints -= apCost;
	}
}

void Character::DrawAP(Graphics & gfx) const
{
	switch (int(actionPoints / 10))
	{
		case 2:
			SpriteCodex::DrawNumber2(Graphics::ScreenWidth - 40, 20, gfx);
			switch (actionPoints % 20)
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
			switch (actionPoints % 10)
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
			switch (actionPoints % 10)
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
