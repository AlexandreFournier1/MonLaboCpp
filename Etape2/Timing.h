#ifndef TIMING_H
#define TIMING_H

class Timing
{
private:
	string day;
	Time start;
	Time duration;
public:
	Timing();
	Timing(Timing &t);
	~Timing();

	string getDay();
	Time getStart();
	Time getDuration();
	string setDay(string d);
	Time setStart(Time s);
	Time setDuration(Time d);
}

#endif