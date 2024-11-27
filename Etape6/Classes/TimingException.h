#ifndef TIMINGEXCEPTION_H
#define TIMINGEXCEPTION_H

#include "Exception.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace planning {

class TimingException : public Exception
{
private:
	int code;
public:
	TimingException();
	TimingException(const TimingException& t);
	TimingException(string m, int c);
	~TimingException();
	
	void setCode(const int c);
	int getCode() const;

	static int const INVALID_DAY, NO_TIMING;
};

}

#endif