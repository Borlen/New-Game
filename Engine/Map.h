#pragma once
#include <set>
#include "Colors.h"
#include "Graphics.h"
#include "Surface.h"
#include "Pos.h"
#include "Time.h"
#include <fstream>

class Map
{
public:
	Map(Pos& in_charPos, Graphics& in_gfx, Time& in_time);
	void Load(std::string filePath);
	void Draw();
	void DrawGrid() const;
	void DrawCharacter(const std::string fileName) const;
	void DrawTileTextures() const;
	void MoveCharacter(Pos& dir) const;
	void MoveCharacterOut();
	void MoveCharacterIn();
	int GetDimension() const;
	int GetWidth() const;
	int GetHeight() const;
	std::string getTileType(const Pos& tilePos) const;
private:
	class Tile
	{
	public:
		Tile();
		void AddType(int in_type);
		void AddRiver(char side);
		void AddRoad(char side);
		void Draw(int x, int y, Graphics& gfx) const;
		bool IsPassable() const;
		int GetTimeCost() const;
		int GetType() const;
	private:
		Surface texture;

		bool passable = true;
		int timeCost;
		int typeID;

		bool riverLeft = false;
		bool riverTop = false;
		bool riverRight = false;
		bool riverBottom = false;
		
		bool roadLeft = false;
		bool roadTop = false;
		bool roadRight = false;
		bool roadBottom = false;

		//Path to folder containing tile textures
		static const std::string basePath;

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
		8 = Field - 2H
		9 = Road - 1H
		River += 1H
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