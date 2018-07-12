#pragma once
#include <set>
#include "Colors.h"
#include "Graphics.h"
#include "SpriteCodex.h"
#include "Pos.h"
#include "Time.h"
#include <fstream>

class Map
{
public:
	Map(Pos& in_charPos, Graphics& in_gfx, Time& in_time);
	void Load(std::string filePath);
	void DrawGrid() const;
	void DrawCharacter() const;
	void DrawTileTextures() const;
	void MoveCharacter(Pos& dir) const;
	int GetDimension() const;
	int GetWidth() const;
	int GetHeight() const;
private:
	class Tile
	{
	public:
		Tile();
		void AddType(int in_type);
		void AddRiver(char side);
		void Draw(int x, int y, Graphics& gfx) const;
		bool IsPassable() const;
		int GetTimeCost() const;
	private:
		struct Type
		{
			void(*Draw)(int x, int y, Graphics& gfx);
			bool passable = true;
			int timeCost;
		};
		Type type;
		int typeID;
		bool riverLeft = false;
		bool riverTop = false;
		bool riverRight = false;
		bool riverBottom = false;

		/*
		Default: River can be added

		0 = Map Border - Unaccessable, nothing can be added
		1 = Forest - 3H
		2 = Mountain - Unaccessable, nothing can be addedd
		3 = Swamp - 6H
		4 = Plains - 2H
		5 = Village Size 1 - 1H
		6 = Village Size 2 - 1H
		7 = Village Size 3 - 1H
		8 = Field = 2H
		9 = LeftRoad - 1H
		10 = LeftTopRoad - 1H
		11 = LeftRightRoad - 1H
		12 = LeftBottomRoad - 1H
		13 = LeftBottomRightRoad - 1H
		14 = LeftTopRightRoad - 1H
		15 = LeftTopBottomRoad - 1H
		16 = LeftTopRightBottomRoad - 1H
		17 = TopRoad - 1H
		18 = TopRightRoad - 1H
		19 - TopBottomRoad - 1H
		20 = TopRightBottomRoad - 1H
		21 = RightRoad - 1H
		22 = RightBottomRoad - 1H
		23 = BottomRoad - 1H
		LeftRiver - 2H
		TopRiver - 2H
		RightRiver - 2H
		BottomRiver - 2H
		*/
	};
	static constexpr int dimension = 25;
	static constexpr int width = 15;
	static constexpr int height = 15;
	Tile tiles[width][height];
	const Color color = Colors::White;
	Pos& characterPos;
	Graphics& gfx;
	Time& time;
};