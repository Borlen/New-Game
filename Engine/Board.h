#pragma once

#include "Graphics.h"
#include "Vec2.h"

class Board 
{
public:
	Board(Graphics& in_gfx);
	void Draw() const;
	int GetDimension() const;
	int GetTileType(const Vec2& moveTo) const;
	bool MoveCharacter(const Vec2& dir, const Vec2& characterPos);
	void DrawTime() const;
	void DrawBorder() const;
	void DrawTileTextures() const;
private:
	class Tile
	{
	public:
		int properties[20];
	};
private:
	static constexpr int dimension = 25;
	static constexpr int mapWidth = 15;
	static constexpr int mapHeight = 15;
	Tile Tiles[mapWidth][mapHeight];
	Color color = Colors::White;
	Graphics& gfx;
	int time = 0;
};