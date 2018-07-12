#pragma once

#include "Pos.h"
#include "Graphics.h"
#include "Character.h"
#include "Map.h"
#include "Time.h"

class UserInterface
{
public:
	UserInterface(Time&in_time, Character& in_player, Map& in_map, Graphics& in_gfx);
	void DrawTime() const;
	void DrawCharacterInfo() const;
	//void DrawTileInfo() const;
private:
	Time& time;
	Character& player;
	Map& map;
	Graphics& gfx;
};