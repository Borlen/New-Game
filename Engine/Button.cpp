#include "Button.h"

Button::Button()
{
}

Button::Button(int x0, int y0, int x1, int y1, Color bgC, Color txtC, Font& font, Graphics& gfx, bool visible, bool addText, std::string in_text)
	:
	button(x0,x1,y0,y1),
	backgroundColor(bgC),
	textColor(txtC),
	theChosenFont(&font),
	gfx(&gfx),
	showText(addText),
	text(in_text)
{
}

bool Button::Clicked(int x, int y)
{
	return false;
}

void Button::Draw() const
{
	for (int i = button.left; i <= button.right; i++)
	{
		for (int j = button.top; j <= button.bottom; j++)
		{
			gfx->PutPixel(i, j, backgroundColor);
		}
	}
	if (showText)
	{
		theChosenFont->DrawText(text, { button.left + (button.right - button.left) / 2, button.top + (button.bottom - button.top) / 2 }, textColor, *gfx, true);
	}
}

bool Button::IsVisible()
{
	return visible;
}
