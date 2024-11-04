#ifndef SCHEDULABLE_H
#define SCHEDULABLE_H

#include <iostream> 
#include <string> 

using namespace std;

class Schedulable
{
protected:
	int id;

public:
	Schedulable();
	Schedulable(int i);
	Schedulable(const Schedulable& id);
	~Schedulable();

	void setId(const int i);
	int getId() const;
	
	virtual string toString() const = 0; // méthode virtuelle pure
	virtual string tuple() const = 0; // méthode virtuelle pure
};

#endif