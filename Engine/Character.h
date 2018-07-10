#pragma once

#include "Graphics.h"
#include "Board.h"

class Character
{
public:
	Character(Vec2& in_mapSize);
	void Draw(Graphics& gfx, int dimension) const;
	void Move(const Vec2& dir, int idTileType);
	void DrawAP(Graphics& gfx) const;
	Vec2& GetPos();
private:
	Vec2 pos = { 0.0f,0.0f };
	Color color = Colors::White;
	Vec2 mapSize;
	int actionPoints = 24;
};