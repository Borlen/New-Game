#pragma once

#include "Graphics.h"
#include "Pos.h"

class Character
{
public:
	void Move(const Pos& dir, bool canMove);
	void Draw(int mapDimension, Pos& offset, int margin, Graphics& gfx) const;
	Pos& GetPos();
private:
	Pos pos = { 0,0 };
	Color color = Colors::White;
};