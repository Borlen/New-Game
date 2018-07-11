#include "Character.h"
#include <assert.h>
#include "SpriteCodex.h"

void Character::Draw(Graphics & gfx, int dimension) const
{
	SpriteCodex::DrawCharacter(pos.x*dimension, pos.y*dimension, gfx);
}

void Character::Move(const Vec2& dir, bool canGo)
{
	if (canGo)
	{
		pos += dir;
	}
}

Vec2 & Character::GetPos()
{
	return pos;
}