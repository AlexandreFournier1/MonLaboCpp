// Fichier .h :
// déclaration de la classe et la déclaration des méthodes dedans
// Variable membre statique : on les déclare dans le .h et on les initialise dans le .cpp

#ifndef EVENT_H // si la macro n'est pas définie, je la défini
#define EVENT_H

#include "Timing.h"

namespace planning {

class Event
{
private:
	int code;
	char* title;
	Timing* timing;
public:
	Event();
	Event(int c, const char *t);
	Event(const Event &e);
	~Event(); // pour supprimer les variables pointeurs

	void setCode(int c);
	void setTitle(const char *t);
	void setTiming(const Timing& t);

	int getCode() const;
	const char * getTitle() const;
	Timing getTiming() const; // pas de pointeur car on retourne un objet et non un pointeur

	void display() const;

	static int currentCode;
};

}

#endif