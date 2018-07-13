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
#include <random>
#include "SpriteEffect.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	time(0, 0, 0, 0, 0),
	map(player.GetPos(), gfx, time),
	userInterface(time, player, map, gfx)
{
	wnd.kbd.DisableAutorepeat();
	std::mt19937 rng(69);
	std::uniform_int_distribution<int> xd(0, Graphics::ScreenWidth - s.GetWidth() - 1);
	std::uniform_int_distribution<int> yd(0, Graphics::ScreenHeight - s.GetHeight() - 1);

	for (int i = 0; i < 50; i++)
	{
		positions.push_back({ xd(rng),yd(rng) });
	}
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
	for (const auto& pos : positions)
	{
		gfx.DrawSprite(pos.x, pos.y, s, SpriteEffect::Copy{});
	}
}
