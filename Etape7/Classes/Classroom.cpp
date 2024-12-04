#include "Classroom.h"

//#define DEBUG

Classroom::Classroom():Schedulable()
{
	#ifdef DEBUG
		cout << "[Classroom] Appel constructeur par défaut" << endl;
	#endif

	setName("vide");
	setSeatingCapacity(0);
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Classroom::Classroom(const Classroom& c):Schedulable(c)
{
	#ifdef DEBUG
		cout << "[Classroom] Appel constructeur de copie" << endl;
	#endif

	setName(c.getName());
	setSeatingCapacity(c.getSeatingCapacity());
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Classroom::Classroom(int i, string n, int s):Schedulable(i)
{
	#ifdef DEBUG
		cout << "[Classroom] Appel constructeur d'initialisation" << endl;
	#endif

	setName(n);
	setSeatingCapacity(s);
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Classroom::~Classroom()
{
	#ifdef DEBUG
		cout << "[Classroom] Appel destructeur" << endl;
	#endif
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void Classroom::setName(const string n)
{
	name = n;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void Classroom::setSeatingCapacity(const int s)
{
	seatingCapacity = s;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

string Classroom::getName() const
{
	return name;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

int Classroom::getSeatingCapacity() const
{
	return seatingCapacity;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

string Classroom::toString() const
{
	ostringstream oss;
	oss << this->getName() << " (" << this->getSeatingCapacity() << ")" << endl;
	return oss.str();
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

string Classroom::tuple() const
{
	ostringstream oss;
	oss << to_string(this->getId()) << ";" << this->toString() << endl;
	return oss.str();
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

ostream& operator<<(ostream& s, const Classroom& c)
{
	s << "<Classroom>" << endl;
	s << "<id>" << endl;
	s << c.getId() << endl;
	s << "</id>" << endl;
	s << "<name>" << endl;
	s << c.getName() << endl;
	s << "</name>" << endl;
	s << "<seatingCapacity>" << endl;
	s << c.getSeatingCapacity() << endl;
	s << "</seatingCapacity>" << endl;
	s << "</Classroom>";

	return s;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

istream& operator>>(istream& s, Classroom& c)
{
	string line;
	Classroom classroomTemp;

	// Ligne 1 : <Classroom>
	getline(s, line);
	if (line != "<Classroom>") 
	{
		cout << "Format invalide : <Classroom> manquant" << endl;
		exit(0);
	}

	// Ligne 2 : <id>
	getline(s, line);
	if (line != "<id>") 
	{
		cout << "Format invalide : <id> manquant" << endl;
		exit(0);
	}

	// Ligne 3 : id
	getline(s, line);
	classroomTemp.setId(stoi(line));

	// Ligne 4 : </id>
	getline(s, line);
	if (line != "</id>") 
	{
		cout << "Format invalide : </id> manquant" << endl;
		exit(0);
	}

	// Ligne 5 : <name>
	getline(s, line);
	if (line != "<name>") 
	{
		cout << "Format invalide : <name> manquant" << endl;
		exit(0);
	}

	// Ligne 6 : name
	getline(s, line);
	classroomTemp.setName(line);

	// Ligne 7 : </name>
	getline(s, line);
	if (line != "</name>") 
	{
		cout << "Format invalide : </name> manquant" << endl;
		exit(0);
	}

	// Ligne 8 : <seatingCapacity>
	getline(s, line);
	if (line != "<seatingCapacity>") 
	{
		cout << "Format invalide : <seatingCapacity> manquant" << endl;
		exit(0);
	}

	// Ligne 9 : id
	getline(s, line);
	classroomTemp.setSeatingCapacity(stoi(line));

	// Ligne 10 : </seatingCapacity>
	getline(s, line);
	if (line != "</seatingCapacity>") 
	{
		cout << "Format invalide : </seatingCapacity> manquant" << endl;
		exit(0);
	}

	// Ligne 11 : </Classroom>
	getline(s, line);
	if (line != "</Classroom>") 
	{
		cout << "Format invalide : </Classroom> manquant" << endl;
		exit(0);
	}

	c.setId(classroomTemp.getId());
	c.setName(classroomTemp.getName());
	c.setSeatingCapacity(classroomTemp.getSeatingCapacity());

	return s;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Classroom& Classroom::operator=(const Classroom& c)
{
	setName(c.getName());
	setSeatingCapacity(c.getSeatingCapacity());

	return (*this);
}