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
	int days = 7, valid = 0;
	string vec[days] = {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};

	for(int i = 0; i < days - 1; i++)
	{
		if (d == vec[i])
		{
			valid = 1;
		}
	}

	if (!valid) throw TimingException("Invalid Day", TimingException::INVALID_DAY);
	else 
	{
		day = d;
	}
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

ostream& operator<<(ostream& s, const Timing& t)
{
	s << "<Timing>" << endl;
	s << "<day>" << endl;
	s << t.getDay() << endl;
	s << "</day>" << endl;
	s << "<start>" << endl;
	s << t.getStart() << endl;
	s << "</start>" << endl;
	s << "<duration>" << endl;
	s << t.getDuration() << endl;
	s << "</duration>" << endl;
	s << "</Timing>" << endl;

	return s;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

istream& operator>>(istream& s, Timing& t)
{
	string line;
	Timing timingTemp;
	Time startTemp, durationTemp;

	// Ligne 1 : <Timing>
	getline(s, line);
	if (line != "<Timing>") 
	{
		cout << "Format invalide : <Timing> manquant" << endl;
		exit(0);
	}

	// Ligne 2 : <day>
	getline(s, line);
	if (line != "<day>") 
	{
		cout << "Format invalide : <day> manquant" << endl;
		exit(0);
	}

	// Ligne 3 : day
	getline(s, line);
	timingTemp.setDay(line);

	// Ligne 4 : </day>
	getline(s, line);
	if (line != "</day>") 
	{
		cout << "Format invalide : </day> manquant" << endl;
		exit(0);
	}

	// Ligne 5 : <start>
	getline(s, line);
	if (line != "<start>") 
	{
		cout << "Format invalide : <start> manquant" << endl;
		exit(0);
	}

	// Ligne 6-13 : Time
	s >> startTemp;

	// Ligne 14 : </start>
	getline(s, line);
	if (line != "</start>") 
	{
		cout << "Format invalide : </start> manquant" << endl;
		exit(0);
	}

	// Ligne 15 : <duration>
	getline(s, line);
	if (line != "<duration>") 
	{
		cout << "Format invalide : <duration> manquant" << endl;
		exit(0);
	}

	// Ligne 16-23 : Time
	s >> durationTemp;

	// Ligne 24 : </duration>
	getline(s, line);
	if (line != "</duration>") 
	{
		cout << "Format invalide : </duration> manquant" << endl;
		exit(0);
	}

	// Ligne 25 : </Timing>
	getline(s, line);
	if (line != "</Timing>") 
	{
		cout << "Format invalide : </Timing> manquant" << endl;
		exit(0);
	}

	t.setDay(timingTemp.getDay());
	t.setStart(startTemp);
	t.setDuration(timingTemp.getDuration());

	return s;
}

}