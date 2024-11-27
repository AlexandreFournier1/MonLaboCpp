#include "Professor.h"

#define DEBUG

Professor::Professor():Schedulable()
{
	#ifdef DEBUG
		cout << "[Professor] Appel constructeur par défaut" << endl;
	#endif

	setLastName("vide");
	setFirstName("vide");
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Professor::Professor(const Professor& p):Schedulable(p)
{
	#ifdef DEBUG
		cout << "[Professor] Appel constructeur de copie" << endl;
	#endif

	setLastName(p.getLastName());
	setFirstName(p.getLastName());
}

Professor::Professor(int i, string ln, string fn):Schedulable(i)
{
	#ifdef DEBUG
		cout << "[Professor] Appel constructeur d'initialisation" << endl;
	#endif

	setLastName(ln);
	setFirstName(fn);
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Professor::~Professor()
{
	#ifdef DEBUG
		cout << "[Professor] Appel destructeur" << endl;
	#endif
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void Professor::setLastName(const string ln)
{
	lastName = ln;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void Professor::setFirstName(const string fn)
{
	firstName = fn;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

string Professor::getLastName() const
{
	return lastName;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

string Professor::getFirstName() const
{
	return firstName;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

string Professor::toString() const
{
	ostringstream oss;
	oss << this->getLastName() << " " << this->getFirstName() << endl;
	return oss.str();
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

string Professor::tuple() const
{
	ostringstream oss;
	oss << to_string(this->getId()) << ";" << this->getLastName() << ";" << this->getFirstName() << endl;
	return oss.str();
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

ostream& operator<<(ostream& s, const Professor& p)
{
	s << p.toString() << endl;
	return s;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Professor& Professor::operator=(const Professor& p)
{
	setFirstName(p.getFirstName());
	setLastName(p.getLastName());

	return (*this);
}