#pragma once

#include "Graphics.h"
#include "Vec2.h"

class Board 
{
public:
	Board(Graphics& in_gfx);
	void Draw(Graphics& gfx) const;
	int GetDimension() const;
	Vec2 GetMapSize() const;
	int GetTileType(const Vec2& moveTo) const;
private:
	static constexpr int dimension = 25;
	static constexpr int mapWidth = 15;
	static constexpr int mapHeight = 15;
	int Tiles[mapWidth][mapHeight];
	Color color = Colors::White;
	Graphics& gfx;
};