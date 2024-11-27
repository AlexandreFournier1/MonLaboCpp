#ifndef TIMING_H
#define TIMING_H

#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

#include "Time.h"
#include "TimingException.h"

namespace planning {

class Timing
{
private:
	string day;
	Time start;
	Time duration;

	int compT(const Timing& t);
public:
	Timing();
	Timing(const Timing &t);
	Timing(const string& d, const Time& s, const Time& dura);
	~Timing();

	//////////////////////////////////////////////////////////////

	string getDay() const;
	Time getStart() const;
	Time getDuration() const;

	void setDay(const string& d);
	void setStart(const Time& s);
	void setDuration(const Time& d);

	//////////////////////////////////////////////////////////////

	void display() const;

	//////////////////////////////////////////////////////////////

	bool operator<(const Timing&t);
	bool operator>(const Timing&t);
	bool operator==(const Timing&t);

	//////////////////////////////////////////////////////////////

	static string const MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY;
};

}

#endif