#include "UserInterface.h"
#include <assert.h>

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

	theChosenFont.DrawText("Time: " + std::to_string(42) + "H", {x,y + 50}, color, gfx);
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
	theChosenFont.DrawText(std::to_string(time.Get('d')) + "of" + month + ", " + std::to_string(time.Get('y')), { x,y }, color, gfx);
	theChosenFont.DrawText(season, { x + 25,y + 20 }, color, gfx);
	gfx.DrawSprite(x + 20, y + 80, {basePath + "/Time/Clock.bmp"}, SpriteEffect::Chroma(Colors::Black));
	gfx.DrawLine(x + 54, y + 114, 15, (int(time.Get('h')) % 12) * 30 - 90, Colors::White);
}

void UserInterface::DrawCharacterInfo(const Font& theChosenFont) const
{
	Pos mapSize = map.GetSize();
	Pos& characterPos = player.GetPos();
	int x = 20;
	int y = 5;
	theChosenFont.DrawText("X: " + std::to_string(characterPos.x) + "\n" + "Y: " + std::to_string(characterPos.y), { mapSize.x + x, y }, color, gfx);
	theChosenFont.DrawText(map.GetTileType(characterPos), { mapSize.x + x, y + 50 }, color, gfx);
}

void UserInterface::Draw(const Font& theChosenFont) const
{
	DrawTime(theChosenFont);
	DrawCharacterInfo(theChosenFont);
}
