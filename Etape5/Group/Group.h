#ifndef GROUP_H
#define GROUP_H

#include <iostream> 
#include <sstream>
#include <cstring>

#include "Schedulable.h"

using namespace std;

class Group : public Schedulable
{

	friend ostream& operator<<(ostream& s, const Group& g);

private:
	string name;

public:
	Group();
	Group(const Group& g);
	Group(int i, string n);
	~Group();

	void setName(const string n);

	string getName() const;

	Group& operator=(const Group& g);
	
	virtual string toString() const override;
	virtual string tuple() const override;
};

#endif