#ifndef TIMING_H
#define TIMING_H

#include "Time.h"

class Timing
{
private:
	string day;
	Time start;
	Time duration;
public:
	Timing();
	Timing(const Timing &t);
	Timing(const string d, const Time s, const Time dura);
	~Timing();

	string getDay() const;
	Time getStart() const;
	Time getDuration() const;

	void setDay(const string d);
	void setStart(const Time s);
	void setDuration(const Time d);

	void display() const;
};

#endif