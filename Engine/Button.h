#pragma once
#include "Graphics.h"
#include "Font.h"

class Button
{
public:
	Button(Color bgC, Color txtC, std::string text);
	bool Clicked(int x, int y);
	void Draw(Graphics & gfx, Font& theChosenFont) const;
private:
	RectI button = { 400, 580, 400, 450 };
	Color backgroundColor;
	Color textColor;
	std::string text;
};