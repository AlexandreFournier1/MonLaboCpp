#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;

#include "Time.h"

namespace planning {

Time::Time()
{
	setHour(0);
	setMinute(0);
}

Time::Time(const Time &t)
{
	setHour(t.getHour());
	setMinute(t.getMinute());
}

Time::~Time() {}

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

int Time::getHour() const
{
	return hour;
}

int Time::getMinute() const
{
	return minute;
}

void Time::display() const
{
	cout << "Time : " << hour << "h" << minute << endl;
}

}