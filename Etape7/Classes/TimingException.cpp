#include "TimingException.h"

namespace planning {

const int TimingException::INVALID_DAY = 1;
const int TimingException::NO_TIMING = 2; 

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

TimingException::TimingException():Exception()
{
	#ifdef DEBUG
		cout << "[TimingException] Appel constructeur par défaut" << endl;
	#endif

	setCode(0);
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

TimingException::TimingException(const TimingException& t):Exception(t)
{
	#ifdef DEBUG
		cout << "[TimingException] Appel constructeur de copie" << endl;
	#endif

	setCode(t.getCode());
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

TimingException::TimingException(string m, int c):Exception(m)
{
	#ifdef DEBUG
		cout << "[TimingException] Appel constructeur d'initialisation" << endl;
	#endif

	setCode(c);
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

TimingException::~TimingException()
{
	#ifdef DEBUG
		cout << "[TimingException] Appel destructeur" << endl;
	#endif
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
	
void TimingException::setCode(const int c)
{
	code = c;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

int TimingException::getCode() const
{
	return code;
}

}