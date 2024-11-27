#ifndef GROUP_H
#define GROUP_H

#include <iostream> 
#include <sstream>
#include <cstring>

#include "Schedulable.h"

using namespace std;
using namespace planning;

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
	
	string toString() const override;
	string tuple() const override;
};

#endif