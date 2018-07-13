/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"
#include <fstream>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	time(0, 0, 0, 0, 0),
	map(player.GetPos(), gfx, time),
	userInterface(time, player, map, gfx),
	H("Images/Fonts/Chars/CapitalH.bmp"),
	e("Images/Fonts/Chars/E.bmp"),
	l("Images/Fonts/Chars/L.bmp"),
	o("Images/Fonts/Chars/O.bmp"),
	W("Images/Fonts/Chars/CapitalW.bmp"),
	r("Images/Fonts/Chars/R.bmp"),
	d("Images/Fonts/Chars/D.bmp"),
	exM("Images/Fonts/Chars/exM.bmp")
{
	wnd.kbd.DisableAutorepeat();
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	while (!wnd.kbd.KeyIsEmpty())
	{
		Keyboard::Event key = wnd.kbd.ReadKey();
		if (key.IsRelease()) 
		{
			Pos dir;
			switch (key.GetCode()) 
			{
				case VK_LEFT:
					dir = Pos(-1, 0);
					break;
				case VK_UP:
					dir = Pos(0, -1);
					break;
				case VK_RIGHT:
					dir = Pos(1, 0);
					break;
				case VK_DOWN:
					dir = Pos(0, 1);
					break;
			}
			map.MoveCharacter(dir);
		}
	}

	/*
	while (!wnd.mouse.IsEmpty())
	{
		Mouse::Event mouseEvent = wnd.mouse.Read();
		switch (mouseEvent.GetType())
		{
		case Mouse::Event::Type::WheelDown:
			brd.DecreaseZoom();
			break;
		case Mouse::Event::Type::WheelUp:
			brd.IncreaseZoom();
			break;
		}
	}
	*/
}

void Game::Load()
{
}

void Game::ComposeFrame()
{
	map.DrawGrid();
	map.DrawTileTextures();
	map.DrawCharacter();
	userInterface.DrawTime();
	userInterface.DrawCharacterInfo();

	gfx.DrawSprite(500, 500, H, SpriteEffect::Chroma{Colors::Black});
	gfx.DrawSprite(510, 500, e, SpriteEffect::Chroma{ Colors::Black });
	gfx.DrawSprite(520, 500, l, SpriteEffect::Chroma{ Colors::Black });
	gfx.DrawSprite(525, 500, l, SpriteEffect::Chroma{ Colors::Black });
	gfx.DrawSprite(530, 500, o, SpriteEffect::Chroma{ Colors::Black });
	gfx.DrawSprite(560, 500, W, SpriteEffect::Chroma{ Colors::Black });
	gfx.DrawSprite(570, 500, o, SpriteEffect::Chroma{ Colors::Black });
	gfx.DrawSprite(580, 500, r, SpriteEffect::Chroma{ Colors::Black });
	gfx.DrawSprite(590, 500, l, SpriteEffect::Chroma{ Colors::Black });
	gfx.DrawSprite(600, 500, d, SpriteEffect::Chroma{ Colors::Black });
	gfx.DrawSprite(610, 500, exM, SpriteEffect::Chroma{ Colors::Black });
}
