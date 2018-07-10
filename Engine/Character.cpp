#include "Character.h"
#include <assert.h>


void Character::Draw(Graphics & gfx, float dimension) const
{
	
	{
		for (int i = int(dimension/6 + dimension * xPos.x); i + int(dimension * xPos.x) < int(dimension - dimension/6) + 1; i++)
		{
			gfx.PutPixel(i, i, color);
		}

		for (int i = int(dimension - dimension/6 + dimension * xPos.x); i + int(dimension * xPos.x) > int(dimension/6) - 1; i--)
		{
			gfx.PutPixel(i, int(dimension - i), color);
		}
	}
	
}

void Character::Move(Vec2 dir)
{
	assert(abs(dir.x) + abs(dir.y) == 1);
	xPos += dir;
}
