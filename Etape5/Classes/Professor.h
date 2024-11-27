#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <iostream> 
#include <sstream>
#include <cstring> 

#include "Schedulable.h"

using namespace std;
using namespace planning;

class Professor : public Schedulable
{

	friend ostream& operator<<(ostream& s, const Professor& p);

private:
	string lastName;
	string firstName;

public:
	Professor();
	Professor(const Professor& p);
	Professor(int i, string ln, string fn);
	~Professor();

	void setLastName(const string ln);
	void setFirstName(const string fn);

	string getLastName() const;
	string getFirstName() const;

	Professor& operator=(const Professor& p);
	
	string toString() const override;
	string tuple() const override;
};

#endif