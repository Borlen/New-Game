#pragma once

#include "Graphics.h"
#include "Board.h"

class Character
{
public:
	Character(Vec2& in_extent);
	void Draw(Graphics& gfx, int dimension) const;
	void Move(const Vec2& dir);
	void CheckIfInside();
private:
	Vec2 pos = { 0.0f,0.0f };
	Color color = Colors::White;
	Vec2& extent;
};