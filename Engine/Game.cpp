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

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	player(),
	brd(gfx,player.GetPos(),defaultMap)
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
			switch (key.GetCode()) 
			{
				case VK_LEFT:
					player.Move(Vec2(-1,0), brd.MoveCharacter(Vec2(-1, 0)));
					break;
				case VK_UP:
					player.Move(Vec2(0, -1), brd.MoveCharacter(Vec2(0, -1)));
					break;
				case VK_RIGHT:
					player.Move(Vec2(1, 0), brd.MoveCharacter(Vec2(1, 0)));
					break;
				case VK_DOWN:
					player.Move(Vec2(0, 1), brd.MoveCharacter(Vec2(0, 1)));
					break;
			}
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

void Game::ComposeFrame()
{
	brd.Draw();
	player.Draw(gfx, brd.GetDimension(), brd.CharacterIsOnRoad());
}
