#include "Button.h"

Button::Button(Color bgC, Color txtC, std::string text)
	:
	backgroundColor(bgC),
	textColor(txtC),
	text(text)
{
}

bool Button::Clicked(int x, int y)
{
	return false;
}

void Button::Draw(Graphics & gfx, Font& theChosenFont) const
{
	for (int i = button.left; i <= button.right; i++)
	{
		for (int j = button.top; j <= button.bottom; j++)
		{
			gfx.PutPixel(i, j, backgroundColor);
		}
	}
	theChosenFont.DrawText(text, { button.left + (button.right - button.left) / 2 - theChosenFont.GetProportions(text).x/2, button.top + (button.bottom - button.top) / 2 - theChosenFont.GetProportions(text).y / 2 }, textColor, gfx);
}
