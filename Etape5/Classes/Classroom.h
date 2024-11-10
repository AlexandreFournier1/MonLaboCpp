#ifndef CLASSROOM_H
#define CLASSROOM_H

#include <iostream> 
#include <sstream>
#include <cstring>

#include "Schedulable.h"

using namespace std;

class Classroom : public Schedulable
{
	friend ostream& operator<<(ostream& s, const Classroom& c);

private:
	string name;
	int seatingCapacity;

public:
	Classroom();
	Classroom(const Classroom& c);
	Classroom(int i, string n, int s);
	~Classroom();

	void setName(const string n);
	void setSeatingCapacity(const int s);

	string getName() const;
	int getSeatingCapacity() const;

	Classroom& operator=(const Classroom& c);
	
	virtual string toString() const override;
	virtual string tuple() const override;
};

#endif