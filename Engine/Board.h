#pragma once

#include "Vec2.h"
#include "Graphics.h"
//#include <stdlib.h>

class Board 
{
public:
	void Draw(Graphics& gfx) const;
	int GetDimension() const;
	Vec2& GetExtent();
	//void IncreaseZoom();
	//void DecreaseZoom();
	void AddCells();
	void RemoveCells();
private:
	static constexpr int dimension = 31;
	//int zoom = 0;
	Vec2 extent = { 4.0f,4.0f };
	Color color = Colors::White;
};