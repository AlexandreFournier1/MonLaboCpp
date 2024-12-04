#ifndef EVENT_H
#define EVENT_H

#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;

#include "Timing.h"
#include "TimingException.h"

namespace planning {

class Event
{
	friend ostream& operator<<(ostream& s, const Event& e);
	friend istream& operator>>(istream& s, Event& e);

private:
	int code;
	char* title;
	Timing* timing;
public:
	Event();
	Event(int c, const char *t);
	Event(const Event &e);
	~Event(); 

	//////////////////////////////////////////////////////////////

	void setCode(int c);
	void setTitle(const char *t);
	void setTiming(const Timing& t);

	int getCode() const;
	const char * getTitle() const;
	Timing getTiming() const;

	//////////////////////////////////////////////////////////////

	void display() const;
	bool isNull() const;

	//////////////////////////////////////////////////////////////

	static int currentCode;
};

}

#endif