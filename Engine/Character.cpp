#include "Character.h"
#include <assert.h>

void Character::Move(const Pos& dir, bool canMove)
{
	if (canMove)
	{
		pos += dir;
	}
}

Pos& Character::GetPos()
{
	return pos;
}