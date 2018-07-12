#pragma once

#include "Graphics.h"
#include "Pos.h"

class Character
{
public:
	void Move(const Pos& dir);
	Pos& GetPos();
private:
	Pos pos = { 0,0 };
	Color color = Colors::White;
};