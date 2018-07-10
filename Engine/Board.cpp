#include "Board.h"
#include <assert.h>

void Board::Draw(Graphics & gfx) const
{
	for (int y = 0; y < extent.y * dimension + 1; y += dimension)
	{
		for (int x = 0; x < extent.x * dimension; x++)
		{
			gfx.PutPixel(x,y,color);
		}
	}
	for (int x = 0; x < extent.x * dimension + 1; x += dimension)
	{
		for (int y = 0; y < extent.y * dimension; y++)
		{
			gfx.PutPixel(x, y, color);
		}
	}
}

int Board::GetDimension() const
{
	return dimension;
}

Vec2 & Board::GetExtent()
{
	return extent;
}

/*
void Board::IncreaseZoom()
{
	if (dimension * ((zoom + zoomAdd) * extent.x) < Graphics::ScreenWidth -100 && dimension * ((zoom + zoomAdd) * extent.y) < Graphics::ScreenHeight)
	{

		zoom += 5 * int(zoom / 10 + 1);
	}
}

void Board::DecreaseZoom()
{
	if (dimension * ((zoom - zoomSub) * extent.x) > Graphics::ScreenWidth/10 && dimension * ((zoom - zoomSub) * extent.y) > Graphics::ScreenHeight/10)
	{
		zoom -= zoomSub;
	}
}
*/

void Board::AddCells()
{
	if ((extent.x + 1) * dimension < Graphics::ScreenWidth - 100 && (extent.y + 1) * dimension < Graphics::ScreenHeight)
	{
		extent += Vec2(1, 1);
	}
}

void Board::RemoveCells()
{
	if (extent.x > 2)
	{
		extent -= Vec2(1, 1);
	}
}
