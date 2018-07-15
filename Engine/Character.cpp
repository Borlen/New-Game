#include "Character.h"
#include <assert.h>

void Character::Move(const Pos& dir)
{
	pos += dir;
}

Pos& Character::GetPos()
{
	return pos;
}