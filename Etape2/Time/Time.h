#ifndef TIME_H
#define TIME_H

namespace planning {

class Time
{
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
};

}

#endif