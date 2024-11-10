#include "Time.h"
#include "Timing.h"

//#define DEBUG

namespace planning {

const string Timing::MONDAY = "Lundi";
const string Timing::TUESDAY = "Mardi";
const string Timing::WEDNESDAY = "Mercredi";
const string Timing::THURSDAY = "Jeudi";
const string Timing::FRIDAY = "Vendredi";
const string Timing::SATURDAY = "Samedi";
const string Timing::SUNDAY = "Dimanche";

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Timing::Timing()
{
	#ifdef DEBUG
		cout << "[Timing] Appel du constructeur par défaut" << endl;
	#endif

	day = "vide";

	start.setHour(0);
	start.setMinute(0);

	duration.setHour(0);
	duration.setMinute(0);
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Timing::Timing(const Timing &t)
{
	#ifdef DEBUG
		cout << "[Timing] Appel du constructeur de copie" << endl;
	#endif

	setDay(t.getDay());
	setStart(t.getStart());
	setDuration(t.getDuration());
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Timing::Timing(const string& d, const Time& s, const Time& dura)
{
	#ifdef DEBUG
		cout << "[Timing] Appel du constructeur d'initialisation" << endl;
	#endif

	setDay(d);
	setStart(s);
	setDuration(dura);
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Timing::~Timing() 
{
	#ifdef DEBUG
		cout << "[Timing] Appel du destructeur" << endl;
	#endif
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

string Timing::getDay() const
{
	return day;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Time Timing::getStart() const
{
	return start;
}

Time Timing::getDuration() const
{
	return duration;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void Timing::setDay(const string& d)
{
	day = d;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void Timing::setStart(const Time& s)
{
	start.setMinute(s.getMinute());
	start.setHour(s.getHour());
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void Timing::setDuration(const Time& d)
{
	duration.setMinute(d.getMinute());
	duration.setHour(d.getHour());
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void Timing::display() const
{
	cout << "Day : " << day << endl;
	cout << "Start : "; start.display();
	cout << "Duration : "; duration.display();
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

int Timing::compT(const Timing& t)
{
	int posDay, posT, days = 7;
	string vec[days] = {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};

	for (int i = 0; i < days - 1; i++)
	{
		if (vec[i] == day) posDay = i;
		if (vec[i] == t.getDay()) posT = i;
	}

	if (posDay < posT) return -1;
	if (posDay > posT) return 1;

	//if (day < t.getDay()) return -1;
	//if (day > t.getDay()) return 1;

	if (start.getHour() < t.getStart().getHour()) return -1;
	if (start.getHour() > t.getStart().getHour()) return 1;

	if (start.getMinute() < t.getStart().getMinute()) return -1;
	if (start.getMinute() > t.getStart().getMinute()) return 1;

	if (duration.getHour() < t.getDuration().getHour()) return -1;
	if (duration.getHour() > t.getDuration().getHour()) return 1;

	if (duration.getMinute() < t.getDuration().getMinute()) return -1;
	if (duration.getMinute() > t.getDuration().getMinute()) return 1;

	return 0;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

bool Timing::operator<(const Timing&t)
{
	return compT(t) == -1;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

bool Timing::operator>(const Timing&t)
{
	return compT(t) == 1;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

bool Timing::operator==(const Timing&t)
{
	return compT(t) == 0;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

}