#include "UserInterface.h"
#include <assert.h>
#include <sstream>
#include <iomanip>
#include <iostream>

const std::string UserInterface::basePath = "Images/Interface";

UserInterface::UserInterface(Time& in_time, Character& in_player, Map& in_map, Graphics& in_gfx, Color color)
	:
	time(in_time),
	player(in_player),
	map(in_map),
	gfx(in_gfx),
	color(color)
{
}

void UserInterface::DrawTime(const Font& theChosenFont) const
{
	const int y = 5;
	const int x = Graphics::ScreenWidth - 120;
	std::stringstream hours;
	hours << std::setfill('0') << std::setw(2) << std::to_string(time.Get('h'));
	theChosenFont.DrawText("Time: " + hours.str() + "H", {x - 50, y}, color, gfx);
	std::string month;
	std::string season;
	switch (time.Get('o'))
	{
	case 1:
		month = "January";
		season = "Spring";
		break;
	case 2:
		month = "February";
		season = "Spring";
		break;
	case 3:
		month = "March";
		season = "Spring";
		break;
	case 4:
		month = "April";
		season = "Summer";
		break;
	case 5:
		month = "May";
		season = "Summer";
		break;
	case 6:
		month = "June";
		season = "Summer";
		break;
	case 7:
		month = "July";
		season = "Autumn";
		break;
	case 8:
		month = "August";
		season = "Autumn";
	case 9:
		month = "September";
		season = "Autumn";
		break;
	case 10:
		month = "October";
		season = "Winter";
		break;
	case 11:
		month = "November";
		season = "Winter";
		break;
	case 12:
		month = "December";
		season = "Winter";
		break;
	default:
		month = "Error";
		break;
	}
	std::stringstream days;
	days << std::setfill('0') << std::setw(2) << time.Get('d');
	theChosenFont.DrawText(days.str() + " of " + month + ", " + std::to_string(time.Get('y')), { x - 100, y + 110 }, color, gfx);
	theChosenFont.DrawText(season, { x - 35,y + 130 }, color, gfx);
	gfx.DrawSprite(x - 45, y + 20, {basePath + "/Time/Clock.bmp"}, SpriteEffect::Chroma(Colors::Black));
	gfx.DrawLine(x - 11, y + 54, 15, (int(time.Get('h')) % 12) * 30 - 90, Colors::White);
}

void UserInterface::DrawCharacterInfo(const Font& theChosenFont) const
{
	Pos mapSize = map.GetSize();
	Pos& characterPos = player.GetPos();
	int x = 20;
	int y = 5;
	std::stringstream xCoords;
	std::stringstream yCoords;
	xCoords << std::setfill('0') << std::setw(2) << std::to_string(characterPos.x);
	yCoords << std::setfill('0') << std::setw(2) << std::to_string(characterPos.y);
	theChosenFont.DrawText("X: " + xCoords.str(), { mapSize.x + x, y }, color, gfx);
	theChosenFont.DrawText("Y: " + yCoords.str(), { mapSize.x + x, y + 16 }, color, gfx);
	theChosenFont.DrawText(map.GetTileType(characterPos), { mapSize.x + x, y + 50 }, color, gfx);
}

void UserInterface::Draw(const Font& theChosenFont) const
{
	DrawTime(theChosenFont);
	DrawCharacterInfo(theChosenFont);
}
