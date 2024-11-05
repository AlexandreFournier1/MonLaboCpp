#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <cstring>
#include <iostream>

using namespace std;

namespace planning {

class Exception
{
private:
	string message;
public:
	Exception();
	Exception(const Exception& e);
	Exception(const string m);
	~Exception();
	
	void setMessage(string m);
	string getMessage() const;
};

}

#endif