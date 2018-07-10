#pragma once

#include "Graphics.h"

class SpriteCodex
{
public:
	static void DrawLeftArrow(int x, int y, Graphics& gfx);
	static void DrawUpArrow(int x, int y, Graphics& gfx);
	static void DrawRightArrow(int x, int y, Graphics& gfx);
	static void DrawDownArrow(int x, int y, Graphics& gfx);
	static void DrawPlusSymbol(int x, int y, Graphics& gfx);
	static void DrawMinusSymbol(int x, int y, Graphics& gfx);
	static void DrawnMouseScrollDown(int x, int y, Graphics& gfx);
	static void DrawMouseScrollUp(int x, int y, Graphics& gfx);
};