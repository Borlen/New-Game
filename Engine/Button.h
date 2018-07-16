#pragma once
#include "Graphics.h"

class Button
{
public:
	bool Clicked(int x, int y);
	void Draw();
private:
	RectI button = { 0, 0, 100, 100 };
};