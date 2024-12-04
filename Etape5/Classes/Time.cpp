#include "Time.h"

//#define DEBUG

namespace planning {

Time::Time()
{
	#ifdef DEBUG
		cout << "[Time] Appel du constructeur par défaut" << endl;
	#endif

	setHour(0);
	setMinute(0);
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Time::Time(const Time &t)
{
	#ifdef DEBUG
		cout << "[Time] Appel du constructeur de copie" << endl;
	#endif

	setHour(t.getHour());
	setMinute(t.getMinute());
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Time::Time(int duration)
{
	#ifdef DEBUG
		cout << "[Time] Appel du constructeur d'initialisation 2" << endl;
	#endif

	if (duration < 0 || duration > 1440)
	{
		throw TimeException("Time Overflow", TimeException::OVERFLOW);
	}

	setHour(duration/60);
	setMinute(duration%60);
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Time::Time(int h, int m)
{
	#ifdef DEBUG
		cout << "[Time] Appel du constructeur d'initialisation 1" << endl;
	#endif

	setHour(h);
	setMinute(m);
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Time::~Time() 
{
	#ifdef DEBUG
		cout << "[Time] Appel du destructeur" << endl;
	#endif
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void Time::setHour(int h)
{
	if(h < 0 || h > 24)
	{
		throw TimeException("Invalid hour", TimeException::INVALID_HOUR);
	}

	hour = h;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void Time::setMinute(int m)
{
	if(m < 0 || m > 60)
	{
		throw TimeException("Invalid minute", TimeException::INVALID_MINUTE);
	}

	minute = m;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

int Time::getHour() const
{
	return hour;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

int Time::getMinute() const
{
	return minute;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void Time::display() const
{
	cout << "Time : " << setw(2) << setfill('0') << hour << "h" << setw(2) << setfill('0') << minute << endl;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

int Time::compT(const Time& t)
{
	if (hour < t.getHour()) return -1;
	if (hour > t.getHour()) return 1;

	if (minute < t.getMinute()) return -1;
	if (minute > t.getMinute()) return 1;

	return 0;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Time& Time::operator=(const Time &t)
{
	setHour(t.getHour());
	setMinute(t.getMinute());

	return (*this);
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Time operator+(const Time&t, const int m)
{
	int duration;

	duration = m + t.getMinute() + t.getHour() * 60;

	Time tmp(duration);

	return tmp;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Time operator+(const int m, const Time&t)
{
	return t + m;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Time operator+(const Time&t1, const Time&t2)
{
	int duration;

	duration = t1.getMinute() + t2.getMinute() + t1.getHour() * 60 + t2.getHour() * 60;
	
	Time tmp(duration);

 	return tmp;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Time Time::operator-(const int m)
{
	int duration;

	duration = (this->getMinute() + this->getHour() * 60) - m;

	Time tmp(duration);

	return tmp;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Time operator-(const int m, const Time&t)
{
	int duration;

	duration = m - (t.getHour() * 60 + t.getMinute());

	Time tmp(duration);

	return tmp;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Time Time::operator-(const Time&t2)
{
	int duration;

	duration = (this->getMinute() + this->getHour() * 60) - (t2.getMinute() + t2.getHour() * 60);

	Time tmp(duration);

	return tmp;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

ostream& operator<<(ostream& s, const Time& t)
{
	s << "Time : " << setw(2) << setfill('0') << t.getHour() << "h" << setw(2) << setfill('0') << t.getMinute() << endl;
	return s;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

istream& operator>>(istream& s, Time& t)
{
	string tmp;
	Time timeTemp;

	s >> tmp;

	if (tmp.size() != 5) 
	{
		cout << "Invalid Length !" << endl;
		exit(0);
	}

	timeTemp.setHour(stoi(tmp.substr(0,2)));
	timeTemp.setMinute(stoi(tmp.substr(3,2)));

	if (timeTemp.getHour() < 0 || timeTemp.getHour() > 24 || timeTemp.getMinute() < 0 || timeTemp.getMinute() > 60)
	{
		cout << "Invalid Time !" << endl;
		exit(0);
	}

	t.setHour(timeTemp.getHour());
	t.setMinute(timeTemp.getMinute());

	return s;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

bool Time::operator<(const Time&t)
{
	return compT(t) == -1;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

bool Time::operator>(const Time&t)
{
	return compT(t) == 1;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

bool Time::operator==(const Time&t)
{
	return compT(t) == 0;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Time Time::operator++() // pré-incrémentation
{
	/*minute += 30;

    if (minute >= 60)
    {
    	if (hour == 24)
		{
			throw TimeException("Overflow: heures posterieur a 23:59", TimeException::OVERFLOW);
		}

        hour += minute / 60;
        minute = minute % 60;
    }

    if (hour >= 24)
    {
    	//hour = hour % 24;
    	throw TimeException("Overflow: heures posterieur a 23:59", TimeException::OVERFLOW);
    }*/

    return (*this) + 30;
}

//////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////// pas encore corriger à partir d'ici

Time Time::operator++(int) // post-incrémentation
{
	Time tmp(*this);

	minute += 30;

    if (minute >= 60)
    {
    	if (tmp.hour == 24)
		{
			throw TimeException("Overflow: heures posterieur a 23:59", TimeException::OVERFLOW);
		}

        hour += minute / 60;
        minute = minute % 60;
    }

    if (hour >= 24)
    {
    	//hour = hour % 24;
    	throw TimeException("Overflow: heures posterieur a 23:59", TimeException::OVERFLOW);
    }

	return tmp;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Time Time::operator--() // pré-décrémentation
{
	minute -= 30;

    if (minute < 0)
	{
		if (hour == 0)
		{
			throw TimeException("Overflow: heures anterieur a 00:00", TimeException::OVERFLOW);
		}

		hour -= 1;
		minute = 60 + minute;

		/*hour -= -minute / 60;
		minute = 60 - (-minute % 60);*/
	}

	if (hour < 0)
	{
		//hour = 24 - (-hour % 24);
		throw TimeException("Overflow: heures anterieur a 00:00", TimeException::OVERFLOW);
	}

    return (*this);
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Time Time::operator--(int) // post-décrémentation
{
	Time tmp(*this);

	minute -= 30;

    if (minute < 0)
	{
		if (tmp.hour == 0)
		{
			throw TimeException("Overflow: heures anterieur a 00:00", TimeException::OVERFLOW);
		}

		hour -= 1;
		minute = 60 + minute;

		/*hour -= -minute / 60;
		minute = 60 - (-minute % 60);*/
	}

	if (hour < 0)
	{
		//hour = 24 - (-hour % 24);
		throw TimeException("Overflow: heures anterieur a 00:00", TimeException::OVERFLOW);
	}

	return tmp;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

}