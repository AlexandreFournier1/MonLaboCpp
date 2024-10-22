#ifndef TIME_H
#define TIME_H

#include <iomanip>
#include <stdlib.h>
#include <cstring>
#include <string>
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

	friend ostream& operator<<(ostream& s, const Time& t);
	friend istream& operator>>(istream& s, Time& t);

private:
	int hour;
	int minute;

	int compT(const Time& t);
public:
	Time();
	Time(const Time &t);
	Time(int h, int m);
	Time(int duration);
	~Time();

	//////////////////////////////////////////////////////////////

	int getHour() const;
	int getMinute() const;

	void setHour(int h);
	void setMinute(int m);

	//////////////////////////////////////////////////////////////

	void display() const;

	//////////////////////////////////////////////////////////////

	Time& operator=(const Time&t);

	int operator<(const Time&t);
	int operator>(const Time&t);
	int operator==(const Time&t);

	Time operator++();
	Time operator++(int);

	Time operator--();
	Time operator--(int);
};

}

#endif