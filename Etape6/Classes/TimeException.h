#ifndef TIMEEXCEPTION_H
#define TIMEEXCEPTION_H

#include "Exception.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace planning {

class TimeException : public Exception
{
private:
	int code;
public:
	TimeException();
	TimeException(const TimeException& t);
	TimeException(string m, int c);
	~TimeException();
	
	void setCode(const int c);
	int getCode() const;

	static int const INVALID_HOUR, INVALID_MINUTE, OVERFLOW;
};

}

#endif