#pragma once

#include "Graphics.h"
#include "Vec2.h"
#include "Tile.h"

class Character
{
public:
	void Draw(Graphics& gfx, int dimension, bool onRoad) const;
	void Move(const Vec2& dir, bool canGo);
	Vec2& GetPos();
private:
	Tile& currentTile;
	Vec2 pos = { 0.0f,0.0f };
	Color color = Colors::White;
};