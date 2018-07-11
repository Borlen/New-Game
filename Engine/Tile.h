#pragma once

class Tile
{
public:
	Tile();
	void AddProperty(int propertyID, bool replace = false);
	void RemoveProperty(int propertyID);
private:
	int type;
	bool riverLeft;
	bool riverTop;
	bool riverRight;
	bool riverBottom;
	int propertyCount = 0;

	/*
	Default: River can be added

	0 = Map Border - Unaccessable, nothing can be added
	1 = Forest - 3H
	2 = Mountain - Unaccessable, nothing can be addedd
	3 = Swamp - 6H
	4 = LeftRoad - 1H
	5 = TopRoad - 1H
	6 = RightRoad - 1H
	7 = BottomRoad - 1H
	8 = Plains - 2H
	9 = Village Size 1 - 1H
	10 = Village Size 2 - 1H
	11 = Village Size 3 - 1H
	12 = LeftRiver - 2H
	13 = TopRiver - 2H
	14 = RightRiver - 2H
	15 = BottomRiver - 2H
	16 = Field = 2H
	*/
};