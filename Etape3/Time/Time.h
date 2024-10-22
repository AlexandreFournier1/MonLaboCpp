#ifndef TIME_H
#define TIME_H

#include <iomanip>
#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;

namespace planning {

class Time
{
	friend Time operator+(const Time&t, const int m);
	friend Time operator+(const int m, const Time&t);
	friend Time operator+(const Time&t1, const Time&t2);

	friend Time operator-(const Time&t, const int m);
	friend Time operator-(const int m, const Time&t);
	friend Time operator-(const Time&t1, const Time&t2);

private:
	int hour;
	int minute;
public:
	Time();
	Time(const Time &t);
	~Time();
	Time(int h, int m);
	Time(int duration);

	int getHour() const;
	int getMinute() const;

	void setHour(int h);
	void setMinute(int m);

	void display() const;

	Time& operator=(const Time&t);

	
};

}

#endif