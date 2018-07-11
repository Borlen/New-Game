#pragma once
#include <set>
#include "Colors.h"

class Map
{
public:
	void DrawGrid() const;
	void DrawTileTextures() const;
	int GetDimension() const;
	void LoadMap(Map& in_map);
private:
	static constexpr int dimension = 25;
	static constexpr int mapWidth = 15;
	static constexpr int mapHeight = 15;
	Tile Tiles[mapWidth][mapHeight];
	Color color = Colors::White;
};