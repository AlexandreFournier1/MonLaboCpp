#ifndef TIME_H
#define TIME_H

class Time
{
private:
	int hour;
	int minute;
public:
	Time();
	Time(Time &t);
	~Time();
	Time(int h, int m);
	Time(int duration);

	int getHour();
	int getMinute();
	void setHour(int h);
	void setMinute(int m);

	void display();
};

#endif