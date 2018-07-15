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
	void MoveCharacter(Pos& dir);
	void MoveCharacterOut(Pos& dir, int& timeSpent);
	void MoveCharacterIn(Pos& dir, int& timeSpent);
	void Move(const Pos dir);
	int GetDimension() const;
	Pos& GetSize() const;
	std::string getTileType(const Pos& tilePos) const;
private:
	class Tile
	{
	public:
		enum class tileTypes
		{
			forest,
			mountain,
			swamp,
			plains,
			villageSize1,
			villageSize2,
			villageSize3,
			field,
			road
		};
	public:
		Tile();
		void AddType(int in_type);
		void AddRiver(char side);
		void AddRoad(char side);
		void Draw(int x, int y, Graphics& gfx) const;
		bool IsPassable() const;
		int GetTimeCost() const;
		int GetType() const;
		bool IsRiver(Pos& dir) const;
		bool IsRoad(Pos& dir) const;
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
	};

	static constexpr int dimension = 25;
	int width = 20;
	int height = 20;
	int xMapSize = 400;
	int yMapSize = 300;
	int xOffset = 0;
	int yOffset = 0;
	Tile *tiles = new Tile[width*height];
	const Color color = Colors::White;
	Pos& characterPos;
	Graphics& gfx;
	Time& time;
};