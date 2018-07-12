#pragma once
#include <set>
#include "Colors.h"
#include "Graphics.h"
#include "SpriteCodex.h"
#include "Pos.h"

class Map
{
public:
	Map(Pos& in_charPos, Graphics& in_gfx);
	//void LoadMap(Map& in_map);
	void DrawGrid() const;
	void DrawCharacter() const;
	void DrawTileTextures() const;
	//int GetDimension() const;
private:
	class Tile
	{
	public:
		Tile();
		void AddType(int in_type);
		void Draw(int x, int y, Graphics& gfx) const;
	private:
		struct Type
		{
			void(*Draw)(int x, int y, Graphics& gfx);
		};
		Type type;
		bool riverLeft = true;
		bool riverTop = true;
		bool riverRight = true;
		bool riverBottom = true;

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
		LeftRiver - 2H
		TopRiver - 2H
		RightRiver - 2H
		BottomRiver - 2H
		12 = Field = 2H
		*/
	};
	static constexpr int dimension = 25;
	static constexpr int mapWidth = 15;
	static constexpr int mapHeight = 15;
	Tile Tiles[mapWidth][mapHeight];
	Color color = Colors::White;
	Pos& characterPos;
	Graphics& gfx;
};