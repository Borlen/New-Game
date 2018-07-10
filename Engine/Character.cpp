#include "Character.h"
#include <assert.h>


Character::Character(Vec2& in_extent)
		:
	extent(in_extent)
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

void Character::Move(const Vec2& dir)
{
	assert(abs(dir.x) + abs(dir.y) == 1);
	if (pos.x + dir.x >= 0 && pos.x + dir.x < extent.x && pos.y + dir.y >= 0 && pos.y + dir.y < extent.y)
	{
		pos += dir;
	}
}

void Character::CheckIfInside()
{
	if (pos.x + 2 > extent.x)
	{
		pos.x = extent.x - 1;
	}
	if (pos.y + 2 > extent.y)
	{
		pos.y = extent.y - 1;
	}
}
