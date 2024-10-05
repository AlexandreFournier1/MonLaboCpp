#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;

#include "Time.h"

Time::Time()
{
	setHour(0);
	setMinute(0);
}

Time::Time(Time &t)
{
	setHour(t.getHour());
	setMinute(t.getMinute());
}

Time::~Time()
{
	
}

Time::Time(int h, int m)
{
	setHour(h);
	setMinute(m);
}

Time::Time(int duration)
{
	if (duration / 60 == 0)
	{
		setMinute(duration);
		return;
	}

	setHour(duration/60);
	setMinute(duration%60);
}

void Time::setHour(int h)
{
	if(h < 0 || h > 24) return;
	hour = h;
}

void Time::setMinute(int m)
{
	if(m < 0 || m > 60) return;
	minute = m;
}

int Time::getHour()
{
	return hour;
}

int Time::getMinute()
{
	return minute;
}

void Time::display()
{
	cout << "Time : " << hour << "h" << minute << endl;
}
