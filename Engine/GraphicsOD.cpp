#define GOD_GRAPHICS
#include "Graphics.h"

void Graphics::BeginFrame()
{
	// clear the sysbuffer
	memset(pSysBuffer, 0u, sizeof(Color) * Graphics::ScreenHeight * Graphics::ScreenWidth);
}

void Graphics::PutPixel(int x, int y, Color c)
{
	assert(x >= 0);
	assert(x < int(Graphics::ScreenWidth));
	assert(y >= 0);
	assert(y < int(Graphics::ScreenHeight));
	pSysBuffer[Graphics::ScreenWidth * y + x] = c;
}

void Graphics::DrawLine(int x0, int y0, int length, int angle, Color c)
{
	double radians = angle * acos(-1) / 180; // acos(-1) = pi
	int x1 = int(x0 + cos(radians)*length);
	int y1 = int(y0 + sin(radians)*length);

	if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x0 > x1)
		{
			int tmp = x1;
			x1 = x0;
			x0 = tmp;

			tmp = y1;
			y1 = y0;
			y0 = tmp;
		}
		int dX = x1 - x0;
		int dY = y1 - y0;
		int yi = 1;
		if (dY < 0)
		{
			yi = -1;
			dY = -dY;
		}
		int D = 2 * dY - dX;
		int y = y0;
		for (int x = x0; x < x1; x++)
		{
			PutPixel(x, y, c);
			if (D >= 0)
			{
				y += yi;
				D -= 2 * dX;
			}
			D += 2 * dY;
		}
	}
	else
	{
		if (y0 > y1)
		{
			int tmp = y1;
			y1 = y0;
			y0 = tmp;

			tmp = x1;
			x1 = x0;
			x0 = tmp;
		}

		int dX = x1 - x0;
		int dY = y1 - y0;
		int xi = 1;
		if (dX < 0)
		{
			xi = -1;
			dX = -dX;
		}
		int D = 2 * dX - dY;
		int x = x0;
		for (int y = y0; y < y1; y++)
		{
			PutPixel(x, y, c);
			if (D > 0)
			{
				x += xi;
				D -= 2 * dY;
			}
			D += 2 * dX;
		}
	}
}

Color Graphics::GetPixel(int x, int y) const
{
	assert(x >= 0);
	assert(x < int(Graphics::ScreenWidth));
	assert(y >= 0);
	assert(y < int(Graphics::ScreenHeight));
	return pSysBuffer[Graphics::ScreenWidth * y + x];
}

void dummy(Graphics& gfx)
{
	gfx.DrawSprite(0, 0, RectI{ 0,0,0,0 }, RectI{ 0,0,0,0 }, Surface{}, SpriteEffect::Copy{});
	gfx.DrawSprite(0, 0, RectI{ 0,0,0,0 }, RectI{ 0,0,0,0 }, Surface{}, SpriteEffect::Chroma{ Colors::Black });
	gfx.DrawSprite(0, 0, RectI{ 0,0,0,0 }, RectI{ 0,0,0,0 }, Surface{}, SpriteEffect::Substitution{ Colors::Black,Colors::Black });
}
