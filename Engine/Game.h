/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Character.h"
#include "Map.h"
#include "Time.h"
#include "UserInterface.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	Character player;
	Map map;
	Time time;
	UserInterface userInterface;
	/********************************/
};


/*
	int timeSpent = 0;
	int tileTypeID;
	int onRoad = 0;
	for (int i = 0; i < Tiles[int(characterPos.x)][int(characterPos.y)].propertyCount; i++)
	{
		tileTypeID = Tiles[int(characterPos.x)][int(characterPos.y)].properties[i];
		switch (tileTypeID)
		{
		case 4:
			if (dir.x == -1)
			{
				timeSpent = 1;
				onRoad = 4;
			}
		case 5:
			if (dir.x == -1)
			{
				timeSpent = 1;
				onRoad = 5;
			}
		case 6:
			if (dir.x == -1)
			{
				timeSpent = 1;
				onRoad = 6;
			}
		case 7:
			if (dir.x == -1)
			{
				timeSpent = 1;
				onRoad = 7;
			}
		case 12:
			if (dir.x == -1)
			{
				timeSpent += 1;
			}
			break;
		case 13:
			if (dir.y == -1)
			{
				timeSpent += 1;
			}
			break;
		case 14:
			if (dir.x == 1)
			{
				timeSpent += 1;
			}
			break;
		case 15:
			if (dir.y == 1)
			{
				timeSpent += 1;
			}
			break;
		}
	}
	int i = 0;
	while (i < Tiles[int(characterPos.x + dir.x)][int(characterPos.y + dir.y)].propertyCount && timeSpent >= 0)
	{
		tileTypeID = Tiles[int(characterPos.x + dir.x)][int(characterPos.y + dir.y)].properties[i];
		switch (tileTypeID)
		{
		case 1:
			timeSpent += 3;
			break;
		case 2:
			timeSpent = -1;
			break;
		case 3:
			timeSpent += 6;
			break;
		case 4:
			timeSpent += 1;
			break;
		case 5:
			timeSpent += 1;
			break;
		case 6:
			timeSpent += 1;
			break;
		case 7:
			timeSpent += 1;
			break;
		case 8:
			timeSpent += 2;
			break;
		case 9:
			timeSpent += 1;
			break;
		case 10:
			timeSpent += 1;
			break;
		case 11:
			timeSpent += 1;
			break;
		case 12:
			if (dir.x == 1)
			{
				timeSpent += 1;
			}
			break;
		case 13:
			if (dir.y == 1)
			{
				timeSpent += 1;
			}
			break;
		case 14:
			if (dir.x == -1)
			{
				timeSpent += 1;
			}
			break;
		case 15:
			if (dir.y == -1)
			{
				timeSpent += 1;
			}
			break;
		case 16:
			timeSpent += 2;
			break;
		default:
			assert(false);
		}
		i++;
	}
	return timeSpent;
*/