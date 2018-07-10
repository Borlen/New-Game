#pragma once

#include "Graphics.h"
#include "Board.h"

class Character
{
public:
	void Draw(Graphics& gfx, float dimension) const;
	void Move(Vec2 dir);
private:
	Vec2 xPos = { 0.0f,0.0f };
	Color color = Colors::White;
};