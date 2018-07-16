#include "Character.h"
#include <assert.h>

void Character::Move(const Pos& dir, bool canMove)
{
	if (canMove)
	{
		pos += dir;
	}
}

void Character::Draw(int mapDimension, Pos& offset, int margin, Graphics& gfx) const
{
	gfx.DrawSprite((pos.x - offset.x) * mapDimension + 1 + margin, + (pos.y - offset.y) * mapDimension + 1 + margin, { "Images/TileTextures/Character/Character.bmp" }, SpriteEffect::Chroma(Colors::Black));
}

Pos& Character::GetPos()
{
	return pos;
}