#include "UserInterface.h"

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
}

bool UserInterface::MoveCharacter(const Vec2 & dir)
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
