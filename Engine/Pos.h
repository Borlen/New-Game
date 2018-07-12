#pragma once

class Pos
{
public:
	Pos() = default;
	Pos(int x_in, int y_in);
	Pos operator+(const Pos& rhs) const;
	Pos& operator+=(const Pos& rhs);
	Pos operator*(int rhs) const;
	Pos& operator*=(int rhs);
	Pos operator-(const Pos& rhs) const;
	Pos& operator-=(const Pos& rhs);
	double GetLength() const;
	int GetLengthSq() const;
public:
	int x;
	int y;
};