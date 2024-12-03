#include "Event.h"
#include "Timing.h"
#include "Time.h"

//#define DEBUG

namespace planning {

int Event::currentCode = 1;

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Event::Event()
{
	#ifdef DEBUG
		cout << "[Event] Appel constructeur par défaut" << endl;
	#endif

	setCode(currentCode);
	title = nullptr;
	setTitle("default");
	timing = nullptr;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Event::Event(int c, const char *t)
{
	#ifdef DEBUG
		cout << "[Event] Appel du constructeur d'initialisation" << endl;
	#endif

	setCode(c);
	currentCode = c;
	title = nullptr;
	setTitle(t);
	timing = nullptr;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Event::Event(const Event &e)
{
	#ifdef DEBUG
		cout << "[Event] Appel du constructeur de copie" << endl;
	#endif

	setCode(e.getCode());
	title = nullptr;
	setTitle(e.getTitle());
	timing = nullptr;
	setTiming(e.getTiming());
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Event::~Event()
{
	#ifdef DEBUG
		cout << "[Event] Appel du destructeur" << endl;
	#endif

	if (title) delete title;
	if (timing) delete timing;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void Event::setCode(int c)
{
	if(c <= 0) return;
	code = c;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void Event::setTitle(const char *t)
{
	if (title) delete title;
	title = new char[strlen(t) + 1];
	strcpy(title, t);
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void Event::setTiming(const Timing& t)
{
	timing = new Timing(t);
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

int Event::getCode() const
{
	return code;
}

const char * Event::getTitle() const
{
	return title;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Timing Event::getTiming() const
{
	if (timing == nullptr)
	{
		throw TimingException("No Timing", TimingException::NO_TIMING);
	}
	
	else 
	{
		return *timing;
	}
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void Event::display() const
{
	cout << "Event (" << code << ") :" << title << endl;
	if (!timing) return;
	timing->display();
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

bool Event::isNull() const
{
	return timing == nullptr;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

ostream& operator<<(ostream& s, const Event& e)
{
	s << "<Event>" << endl;
	s << "<code>" << endl;
	s << e.getCode() << endl;
	s << "</code>" << endl;
	s << "<title>" << endl;
	s << e.getTitle() << endl;
	s << "</title>" << endl;

	if (!(e.isNull()))
	{
		s << "<timing>" << endl;
		s << e.getTiming();
		s << "</timing>" << endl;
	}

	s << "</Event>";

	return s;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

istream& operator>>(istream& s, Event& e)
{
	string line;
	Event eventTemp;
	Timing timingTemp;

	// Ligne 1 : <Event>
	getline(s, line);
	if (line != "<Event>") 
	{
		cout << "Format invalide : <Event> manquant" << endl;
		exit(0);
	}

	// Ligne 2 : <code>
	getline(s, line);
	if (line != "<code>") 
	{
		cout << "Format invalide : <code> manquant" << endl;
		exit(0);
	}

	// Ligne 3 : code
	getline(s, line);
	eventTemp.setCode(stoi(line));

	// Ligne 4 : </code>
	getline(s, line);
	if (line != "</code>") 
	{
		cout << "Format invalide : </code> manquant" << endl;
		exit(0);
	}

	// Ligne 5 : <title>
	getline(s, line);
	if (line != "<title>") 
	{
		cout << "Format invalide : <title> manquant" << endl;
		exit(0);
	}

	// Ligne 6 : title
	getline(s, line);
	eventTemp.setTitle(line.data());

	// Ligne 7 : </title>
	getline(s, line);
	if (line != "</title>") 
	{
		cout << "Format invalide : </title> manquant" << endl;
		exit(0);
	}

	if (!(e.isNull()))
	{
		// Ligne 8 : <timing>
		getline(s, line);
		if (line != "<timing>") 
		{
			cout << "Format invalide : <timing> manquant" << endl;
			exit(0);
		}

		// Ligne 9-34 : timing
        s >> timingTemp;

        // Ligne 35 : </timing>
        getline(s, line);
        if (line != "</timing>") 
        {
            cout << "Format invalide : </timing> manquant" << endl;
            exit(0);
        }

        e.setTiming(timingTemp);
	}
    //else e.setTiming(nullptr);

	// Ligne 8 ou 36 : </Event>
	getline(s, line);
	if (line != "</Event>") 
	{
		cout << "Format invalide : </Event> manquant" << endl;
		exit(0);
	}

	e.setCode(eventTemp.getCode());
	e.setTitle(eventTemp.getTitle());

	return s;
}


}