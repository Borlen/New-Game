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

	theChosenFont.DrawText("Time: " + std::to_string(42) + "H", {x,y}, color, gfx);
	gfx.DrawSprite(x + 20, y + 30, {basePath + "/Time/Clock.bmp"}, SpriteEffect::Chroma(Colors::Black));
	gfx.DrawLine(x + 54, y + 64, 15, (int(time.Get('h')) % 12) * 30 - 90, Colors::White);
}

void UserInterface::DrawCharacterInfo(const Font& theChosenFont) const
{
	int mapWidth = map.GetWidth();
	int mapHeight = map.GetHeight();
	int mapDimension = map.GetDimension();
	Pos& characterPos = player.GetPos();
	int x = 20;
	int y = 5;
	theChosenFont.DrawText("X: " + std::to_string(characterPos.x) + "\n" + "Y: " + std::to_string(characterPos.y), { mapWidth * mapDimension + x, y }, color, gfx);
	theChosenFont.DrawText(map.getTileType(characterPos), { mapWidth * mapDimension + x, y + 50 }, color, gfx);
}

void UserInterface::Draw(const Font& theChosenFont) const
{
	DrawTime(theChosenFont);
	DrawCharacterInfo(theChosenFont);
}
