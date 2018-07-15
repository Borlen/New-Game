#pragma once

#include "Pos.h"
#include "Graphics.h"
#include "Character.h"
#include "Map.h"
#include "Time.h"
#include "Font.h"

class UserInterface
{
public:
	UserInterface(Time&in_time, Character& in_player, Map& in_map, Graphics& in_gfx, Color color = Colors::White);
	void DrawTime(const Font& theChosenFont) const;
	void DrawCharacterInfo(const Font& theChosenFont) const;
	void Draw(const Font& theChosenFont) const;
	//void DrawTileInfo() const;
private:
	static const std::string basePath;
	Time& time;
	Character& player;
	Map& map;
	Graphics& gfx;
	Color color;
};