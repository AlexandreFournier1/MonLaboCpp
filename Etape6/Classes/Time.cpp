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

	if (duration / 60 == 0)
	{
		setMinute(duration);
		setHour(0);
		return;
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
	Time tmp(t);

	tmp.minute += m;

	if (tmp.minute >= 60)
	{
		if (tmp.hour == 24)
		{
			throw TimeException("Overflow: heures posterieur a 23:59", TimeException::OVERFLOW);
		}

		tmp.hour += tmp.minute / 60;
		tmp.minute = tmp.minute % 60;
	}

	if (tmp.hour >= 24)
	{
		//tmp.hour = tmp.hour % 24;
		throw TimeException("Overflow: heures posterieur a 23:59", TimeException::OVERFLOW);
	}

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
	Time tmp;

	tmp.hour = t1.getHour() + t2.getHour();
	tmp.minute = t1.getMinute() + t2.getMinute();

	if (tmp.minute >= 60)
	{
		if (tmp.hour == 24)
		{
			throw TimeException("Overflow: heures posterieur a 23:59", TimeException::OVERFLOW);
		}

		tmp.hour += tmp.minute / 60;
		tmp.minute = tmp.minute % 60;
	}

	if (tmp.hour >= 24)
	{
		//tmp.hour = tmp.hour % 24;
		throw TimeException("Overflow: heures posterieur a 23:59", TimeException::OVERFLOW);
	}

 	return tmp;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Time Time::operator-(const int m)
{
	Time tmp(*this);

	tmp.minute = (tmp.hour * 60 + tmp.minute) - m;

	if (tmp.minute >= 60)
	{
		tmp.hour = tmp.minute / 60;
		tmp.minute = tmp.minute % 60;
	}

	if (tmp.hour >= 24)
	{
		tmp.hour = tmp.hour % 24;
	}

	if (tmp.minute < 0)
	{
		if (tmp.hour == 0)
		{
			throw TimeException("Overflow: heures anterieur a 00:00", TimeException::OVERFLOW);
		}

		tmp.hour -= -tmp.minute / 60;
		tmp.minute = 60 - (-tmp.minute % 60);
	}

	if (tmp.hour < 0)
	{
		//tmp.hour = 24 - (-tmp.hour % 24);
		throw TimeException("Overflow: heures anterieur a 00:00", TimeException::OVERFLOW);
	}

	return tmp;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Time operator-(const int m, const Time&t)
{
	Time tmp;

	tmp.minute = m - (t.hour * 60 + t.minute);

	if (tmp.minute < 0)
	{
		if (tmp.hour == 0)
		{
			throw TimeException("Overflow: heures anterieur a 00:00", TimeException::OVERFLOW);
		}

		tmp.hour -= -tmp.minute / 60;
		tmp.minute = 60 - (-tmp.minute % 60);
	}

	if (tmp.hour < 0)
	{
		//tmp.hour = 24 - (-tmp.hour % 24);
		throw TimeException("Overflow: heures anterieur a 00:00", TimeException::OVERFLOW);
	}

	return tmp;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Time Time::operator-(const Time&t2)
{
	Time tmp;
	Time t1(*this);

	tmp.hour = t1.hour - t2.hour;
	tmp.minute = t1.minute - t2.minute;

	if (tmp.minute < 0)
	{
		if (tmp.hour == 0)
		{
			throw TimeException("Overflow: heures anterieur a 00:00", TimeException::OVERFLOW);
		}

		tmp.hour -= -tmp.minute / 60;
		tmp.minute = 60 - (-tmp.minute % 60);
	}

	if (tmp.hour < 0)
	{
		//tmp.hour = 24 - (-tmp.hour % 24);
		throw TimeException("Overflow: heures anterieur a 00:00", TimeException::OVERFLOW);
	}

	return tmp;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

ostream& operator<<(ostream& s, const Time& t)
{
	s << "<Time>" << endl;
	s << "<hour>" << endl;
	s << setw(2) << setfill('0') << t.getHour() << endl;
	s << "</hour>" << endl;
	s << "<minute>" << endl;
	s << setw(2) << setfill('0') << t.getMinute() << endl;
	s << "</minute>" << endl;
	s << "</Time>";

	return s;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

istream& operator>>(istream& s, Time& t)
{
	string line;
	Time timeTemp;

	// Ligne 1 : <Time>
	getline(s, line);
	if (line != "<Time>") 
	{
		cout << "Format invalide : <Time> manquant" << endl;
		exit(0);
	}

	// Ligne 2 : <hour>
	getline(s, line);
	if (line != "<hour>") 
	{
		cout << "Format invalide : <hour> manquant" << endl;
		exit(0);
	}

	// Ligne 3 : heure
	getline(s, line);
	timeTemp.setHour(stoi(line));

	// Ligne 4 : </hour>
	getline(s, line);
	if (line != "</hour>") 
	{
		cout << "Format invalide : <hour> manquant" << endl;
		exit(0);
	}

	// Ligne 5 : <minute>
	getline(s, line);
	if (line != "<minute>") 
	{
		cout << "Format invalide : <minute> manquant" << endl;
		exit(0);
	}

	// Ligne 6 : minute
	getline(s, line);
	timeTemp.setMinute(stoi(line));

	// Ligne 7 : </minute>
	getline(s, line);
	if (line != "</minute>") 
	{
		cout << "Format invalide : <minute> manquant" << endl;
		exit(0);
	}

	// Ligne 8 : </Time>
	getline(s, line);
	if (line != "</Time>") 
	{
		cout << "Format invalide : </Time> manquant" << endl;
		exit(1);
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
	minute += 30;

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
    }

    return (*this);
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

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