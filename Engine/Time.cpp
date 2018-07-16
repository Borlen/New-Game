#include "Time.h"
#include <assert.h>

Time::Time(int m, int h, int d, int o, int y)
	:
	minutes(m),
	hours(h),
	days(d),
	months(o),
	years(y)
{
}

void Time::Add(int time, char format)
{
	switch (format)
	{
	case 'm':
		minutes += time;
		break;
	case 'h':
		hours += time;
		break;
	case 'd':
		days += time;
		break;
	case 'o':
		months += time;
		break;
	case 'y':
		years += time;
		break;
	}
	CheckTime();
}

int Time::Get(char format) const
{
	switch (format)
	{
	case 'm':
		return minutes;
		//return float(minutes + hours * 60 + days * 60 * 24 + months * 29 * 24 * 60 + years * 12 * 29 * 24 * 60);
	case 'h':
		return hours;
		//return float(hours / 60 + hours + days * 24 + months * 29 * 24 + years * 12 * 29 * 24);
	case 'd':
		return days;
		//return float(days / 60 / 24 + hours / 24 + days + months * 29 + years * 12 * 29);
	case 'o':
		return months;
		//return float(months / 60 / 24 / 29 + hours / 24 / 29 + days / 29 + months + years * 12);
	case 'y':
		return years;
		//return float(years / 60 / 24 / 29 / 12 + hours / 24 / 29 / 12 + days / 29 / 12 + months / 12 + years);
	default:
		assert(false);
		return 0;
	}
}

void Time::CheckTime()
{
	if (minutes > 60)
	{
		hours += int(minutes / 60);
		minutes = minutes % 60;
	}

	if (hours > 24)
	{
		days += int(hours / 24);
		hours = hours % 24;
	}

	if (days > 29)
	{
		months += int(days / 29);
		days = days % 29;
	}

	if (months > 12)
	{
		years += int(months / 12);
		months = months % 12;
	}
}
