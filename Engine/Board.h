#pragma once

#include "Vec2.h"
#include "Graphics.h"

class Board 
{
public:
	void AddRow();
	void AddColumn();
	void Draw(Graphics& gfx) const;
	float GetDimension() const;
	void IncreaseZoom();
	void DecreaseZoom();
private:
	static constexpr int dimension = 30;
	float zoom = 1;
	Vec2 extent = { 4,4 };
	Color color = Colors::White;
	float zoomAdd = 0.2f;
	float zoomSub = 0.2f;
};