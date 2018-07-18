#pragma once

#include "Graphics.h"
#include "Surface.h"
#include "Pos.h"

class Font
{
public:
	Font(const std::string& filePath, int spacing, int glyphHeight, char firstChar = ' ', char LastChar = '~', Color chroma = Colors::Black);
	void DrawText(const std::string& text, const Pos& pos, Color color, Graphics& gfx, bool inMiddle = false) const;
	Pos	GetProportions(const std::string& text) const;
private:
	// holds the font sheet bitmap data
	Surface chars[128];
	//Spacing between character
	int glyphHeight;
	int spacing;
	char firstChar;
	char lastChar;
	// font sheet chroma color
	Color chroma;
};