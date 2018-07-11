#include "Character.h"
#include <assert.h>
#include "SpriteCodex.h"

void Character::Draw(Graphics & gfx, int dimension, bool onRoad) const
{
	if (onRoad)
	{
		SpriteCodex::DrawCharacterWithHorse(int(pos.x*dimension), int(pos.y*dimension), gfx);
	}
	else
	{
		SpriteCodex::DrawCharacter(int(pos.x*dimension), int(pos.y*dimension), gfx);
	}

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