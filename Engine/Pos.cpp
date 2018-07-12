#include "Pos.h"
#include <cmath>

Pos::Pos(int x_in, int y_in)
	:
	x(x_in),
	y(y_in)
{
}

Pos Pos::operator+(const Pos& rhs) const
{
	return Pos(x + rhs.x, y + rhs.y);
}

Pos& Pos::operator+=(const Pos& rhs)
{
	return *this = *this + rhs;
}

Pos Pos::operator*(int rhs) const
{
	return Pos(x * rhs, y * rhs);
}

Pos& Pos::operator*=(int rhs)
{
	return *this = *this * rhs;
}

Pos Pos::operator-(const Pos& rhs) const
{
	return Pos(x - rhs.x, y - rhs.y);
}

Pos& Pos::operator-=(const Pos& rhs)
{
	return *this = *this - rhs;
}

double Pos::GetLength() const
{
	return std::sqrt(GetLengthSq());
}

int Pos::GetLengthSq() const
{
	return x * x + y * y;
}