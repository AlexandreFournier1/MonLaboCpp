#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

#include "Time.h"
#include "Timing.h"

namespace planning {

const string Timing::MONDAY = "Lundi";
const string Timing::TUESDAY = "Mardi";
const string Timing::WEDNESDAY = "Mercredi";
const string Timing::THURSDAY = "Jeudi";
const string Timing::FRIDAY = "Vendredi";
const string Timing::SATURDAY = "Samedi";
const string Timing::SUNDAY = "Dimanche";

Timing::Timing()
{
	day = "vide";

	start.setHour(0);
	start.setMinute(0);

	duration.setHour(0);
	duration.setMinute(0);
}

Timing::Timing(const Timing &t)
{
	setDay(t.getDay());
	setStart(t.getStart());
	setDuration(t.getDuration());
}

Timing::Timing(const string& d, const Time& s, const Time& dura)
{
	setDay(d);
	setStart(s);
	setDuration(dura);
}

Timing::~Timing() {}

string Timing::getDay() const
{
	return day;
}

Time Timing::getStart() const
{
	return start;
}

Time Timing::getDuration() const
{
	return duration;
}

void Timing::setDay(const string& d)
{
	day = d;
}

void Timing::setStart(const Time& s)
{
	start = s;
}

void Timing::setDuration(const Time& d)
{
	duration = d;
}

void Timing::display() const
{
	cout << "Day : " << day << endl;
	cout << "Start : " << start.getHour() << "h" << start.getMinute() << endl;
	cout << "Duration : " << duration.getHour() << "h" << duration.getMinute() << endl;
}

}