#include "Font.h"
#include <cassert>
#include "SpriteEffect.h"

Font::Font(const std::string& filePath, int spacing, int glyphHeight, char firstChar, char lastChar, Color chroma)
	:
	chroma(chroma),
	spacing(spacing),
	glyphHeight(glyphHeight),
	firstChar(firstChar),
	lastChar(lastChar)
{
	//might as well skip the SPACE char
	for (int i = 0; i < lastChar - firstChar; i++)
	{
		chars[i] = {filePath + std::to_string(i + firstChar) + ".bmp"};
	}
	if (firstChar == ' ')
	{
		firstChar++;
	}
}
void Font::DrawText(const std::string & text, const Pos & pos, Color color, Graphics & gfx, bool inMiddle) const
{
	// create effect functor
	SpriteEffect::Substitution e{chroma, color};
	// curPos is the pos that we are drawing to on the screen
	Pos curPos;
	if (inMiddle)
	{
		curPos.x = pos.x - int(GetProportions(text).x / 2);
		curPos.y = pos.y - int(GetProportions(text).y / 2);
	}
	else
	{
		curPos = pos;
	}

	for (auto c : text)
	{
		 c = toupper(c);
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
				gfx.DrawSprite(curPos.x, curPos.y, chars[c - firstChar], e);
				curPos.x += chars[c - firstChar].GetWidth() + spacing;
			}
		}
		// advance screen pos for next character
	}
}

Pos Font::GetProportions(const std::string & text) const
{
	Pos curPos(0, glyphHeight);
	for (auto c : text)
	{
		// on a newline character, reset x position and move down by 1 glyph height
		if (c == '\n')
		{
			// carriage return
			curPos.x = 0;
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
				curPos.x += chars[c - firstChar].GetWidth() + spacing;
			}
		}
		// advance screen pos for next character
	}
	return curPos;
}
