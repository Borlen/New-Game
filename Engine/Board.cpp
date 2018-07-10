#include "Board.h"
#include <assert.h>

void Board::AddRow()
{
	extent += Vec2(0, 1);
}

void Board::AddColumn()
{
	extent += Vec2(1, 0);
}

void Board::Draw(Graphics & gfx) const
{
	for (int y = 0; y < int(extent.y * dimension * zoom + 1); y += int(dimension * zoom))
	{
		for (int x = 0; x < int(extent.x * dimension * zoom); x++)
		{
			gfx.PutPixel(x,y,color);
		}
	}
	for (int x = 0; x < int(extent.x * dimension * zoom + 1); x += int(dimension * zoom))
	{
		for (int y = 0; y < int(extent.y * dimension * zoom); y++)
		{
			gfx.PutPixel(x, y, color);
		}
	}
}

float Board::GetDimension() const
{
	return dimension * zoom;
}

void Board::IncreaseZoom()
{
	if (dimension * ((zoom + zoomAdd) * extent.x) < Graphics::ScreenWidth -100 && dimension * ((zoom + zoomAdd) * extent.y) < Graphics::ScreenHeight)
	{
		zoom += zoomAdd;
	}
}

void Board::DecreaseZoom()
{
	if (dimension * ((zoom - zoomSub) * extent.x) > Graphics::ScreenWidth/10 && dimension * ((zoom - zoomSub) * extent.y) > Graphics::ScreenHeight/10)
	{
		zoom -= zoomSub;
	}
}
