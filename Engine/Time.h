#pragma once

class Time
{
public:
	Time(int m, int h, int d, int o, int y);
	void Add(int time, char format);
	int Get(char format) const;
	void CheckTime();
private:
	int minutes;
	int hours;
	int days;
	int months;
	int years;
};