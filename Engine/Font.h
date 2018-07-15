#pragma once

#include "Graphics.h"
#include "Surface.h"
#include "Pos.h"

class Font
{
public:
	Font(const std::string& filename, int glyphWidth, int glyphHeight, char firstChar = ' ', char LastChar = '~', Color chroma = Colors::Black);
	void DrawText(const std::string& text, const Pos& pos, Color color, Graphics& gfx) const;
private:
	RectI MapGlyphRect(char c) const;
private:
	// holds the font sheet bitmap data
	Surface surface;
	//Spacing between character
	int glyphWidth;
	int glyphHeight;
	const char firstChar;
	const char lastChar;
	// font sheet chroma color
	Color chroma;
};