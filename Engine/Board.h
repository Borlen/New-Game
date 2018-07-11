#pragma once

#include "Graphics.h"
#include "Vec2.h"
#include <set>

class Board 
{
public:
	Board(Graphics& in_gfx, Vec2& in_characterPos);
	void Draw() const;
	int GetDimension() const;
	bool MoveCharacter(const Vec2& dir);
	void DrawTime() const;
	void DrawBorder() const;
	void DrawTileTextures() const;
	int GetTimeCost(const Vec2& dir) const;
	void LoadCustomMap();
	void DrawCharacterInfo() const;
private:
	class Tile
	{
	public:
		Tile();
		void AddProperty(int propertyID, bool replace = false);
		void RemoveProperty(int propertyID);
		static constexpr int nTypes = 16;
		int properties[nTypes];
		int propertyCount = 0;
		std::set<int> Main;
		std::set<int> Sides;

		/*
		Default: River can be added

		0 = Map Border - Unaccessable, nothing can be added
		1 = Forest - 3H
		2 = Mountain - Unaccessable, nothing can be addedd
		3 = Swamp - 6H
		4 = LeftRoad - 1H
		5 = TopRoad - 1H
		6 = RightRoad - 1H
		7 = BottomRoad - 1H
		8 = Plains - 2H
		9 = Village Size 1 - 1H
		10 = Village Size 2 - 1H
		11 = Village Size 3 - 1H
		12 = LeftRiver - 2H
		13 = TopRiver - 2H
		14 = RightRiver - 2H
		15 = BottomRiver - 2H
		16 = Field = 2H
		*/
	};
private:
	static constexpr int dimension = 25;
	static constexpr int mapWidth = 15;
	static constexpr int mapHeight = 15;
	Tile Tiles[mapWidth][mapHeight];
	Color color = Colors::White;
	Graphics& gfx;
	Vec2& characterPos;
	int time = 0;
};