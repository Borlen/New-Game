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
#include <fstream>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	time(0, 6, 1, 1, 1420),
	map(player.GetPos(), gfx, time),
	userInterface(time, player, map, gfx),
	homemadeFont("chars/", 4, 12, ' ', 127)
{
	buttons[0] = { 400, 400, 500, 500, Colors::Gray, Colors::White, homemadeFont, gfx, false, true, "CLICK ME" };
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
			bool movePlayer = false;
			switch (key.GetCode()) 
			{
				case VK_LEFT:
					dir = Pos(-1, 0);
					movePlayer = true;
					break;
				case VK_UP:
					dir = Pos(0, -1);
					movePlayer = true;
					break;
				case VK_RIGHT:
					dir = Pos(1, 0);
					movePlayer = true;
					break;
				case VK_DOWN:
					dir = Pos(0, 1);
					movePlayer = true;
					break;
			}
			if (movePlayer) 
			{
				player.Move(dir, map.MoveCharacter(dir));
			}
		}
	}

	while (!wnd.mouse.IsEmpty())
	{
		Mouse::Event mouseEvent = wnd.mouse.Read();
		switch (mouseEvent.GetType())
		{
		case Mouse::Event::Type::LRelease:
			std::pair<int, int> clickPos = mouseEvent.GetPos();
			for (int i = 0; i < buttonCount; i++)
			{
				if (buttons[i].IsVisible())
				{

				}
			}
			break;
		}
	}
}

void Game::Load()
{
}

void Game::ComposeFrame()
{
	map.Draw();
	player.Draw(map.GetDimension(), map.GetOffset(), map.GetMargin(), gfx);
	userInterface.Draw(homemadeFont);
	for (int i = 0; i < buttonCount; i++)
	{
		if (buttons[i].IsVisible())
		{
			buttons[i].Draw();
		}
	}
}
