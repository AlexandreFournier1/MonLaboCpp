#include "Schedulable.h"

#define DEBUG

namespace planning {

Schedulable::Schedulable()
{
	#ifdef DEBUG
		cout << "[Schedulable] Appel constructeur par défaut" << endl;
	#endif

	setId(0);
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Schedulable::Schedulable(const Schedulable& id)
{
	#ifdef DEBUG
		cout << "[Schedulable] Appel constructeur de copie" << endl;
	#endif

	setId(id.getId());
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Schedulable::Schedulable(int i)
{
	#ifdef DEBUG
		cout << "[Schedulable] Appel constructeur d'initialisation" << endl;
	#endif

	setId(i);
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

Schedulable::~Schedulable() 
{
	#ifdef DEBUG
		cout << "[Schedulable] Appel destructeur" << endl;
	#endif
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void Schedulable::setId(const int i)
{
	id = i;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

int Schedulable::getId() const
{
	return id;
}

}