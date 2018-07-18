#pragma once
#include "Graphics.h"
#include "Font.h"

class Button
{
public:
	Button();
	Button(int x0, int y0, int x1, int y1, Color bgC, Color txtC, Font& font, Graphics& gfx, bool visible = false, bool addText = false, std::string in_text = " ");
	bool Clicked(int x, int y);
	void Draw() const;
	bool IsVisible();
private:
	RectI button = {0,0,0,0};
	Color backgroundColor;
	Color textColor;
	Font *theChosenFont;
	Graphics *gfx;
	std::string text;
	bool visible;
	bool showText;
};