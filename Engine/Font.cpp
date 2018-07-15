#include "Font.h"
#include <cassert>
#include "SpriteEffect.h"

Font::Font(const std::string& filename, int glyphWidth, int glyphHeight, char firstChar, char lastChar, Color chroma)
	:
	surface(filename),
	chroma(chroma),
	glyphWidth(glyphWidth),
	glyphHeight(glyphHeight),
	firstChar(firstChar),
	lastChar(lastChar)
{
	//might as well skip the SPACE char
	if (firstChar == ' ')
	{
		firstChar++;
	}
}
void Font::DrawText(const std::string & text, const Pos & pos, Color color, Graphics & gfx) const
{
	// create effect functor
	SpriteEffect::Substitution e{chroma, color};
	// curPos is the pos that we are drawing to on the screen
	auto curPos = pos;
	for (auto c : text)
	{
		// on a newline character, reset x position and move down by 1 glyph height
		if (c == '\n')
		{
			// carriage return
			curPos.x = pos.x;
			// line feed
			curPos.y += glyphHeight;
			// we don't want to advance the character position right for a newline
			continue;
		}
		else
		{
			//Only draw characters that are on font sheet
			if (c >= firstChar && c <= lastChar)
			{
				// use DrawSpriteSubstitute so that we can choose the color of the font rendered
				gfx.DrawSprite(curPos.x, curPos.y, MapGlyphRect(c), surface, e);
				curPos.x += glyphWidth;
			}
		}
		// advance screen pos for next character
	}
}

RectI Font::MapGlyphRect(char c) const
{
	assert(c >= firstChar && c <= lastChar);
	//Set the amount of chars in one row
	const int nColumns = surface.GetWidth() / glyphWidth;
	//font sheet glyphs start at ' ', calculate index into the sheet
	const int glyphIndex = c - firstChar;
	//Calculate the x and y coordinate of the char in the bitmap
	const int yGlyph = glyphIndex / nColumns;
	const int xGlyph = glyphIndex % nColumns;
	return RectI({xGlyph * glyphWidth, yGlyph * glyphHeight},
	glyphWidth, glyphHeight);
}
