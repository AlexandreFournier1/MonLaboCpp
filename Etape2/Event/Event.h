// Fichier .h :
// déclaration de la classe et la déclaration des méthodes dedans

#ifndef EVENT_H // si la macro n'est pas définie, je la défini
#define EVENT_H

#include "Timing.h"

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
	void setTiming(Timing* t);

	int getCode() const;
	const char * getTitle() const;
	Timing* getTiming() const;

	void display() const;
};
#endif