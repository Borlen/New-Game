#pragma once

class UserInterface
{
public:
	void DrawTime() const;
	void DrawCharacterInfo() const;
	void DrawTileInfo() const;
	bool MoveCharacter(const Vec2& dir);
	int GetTimeCost(const Vec2& dir) const;
private:
};