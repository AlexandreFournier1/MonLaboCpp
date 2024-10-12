#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;

#include "Event.h"
#include "Timing.h"
#include "Time.h"

namespace planning {

int Event::currentCode = 1;

Event::Event() // constructeur par défaut
{
	setCode(currentCode);
	title = nullptr;
	setTitle("default");
	timing = nullptr;
}

Event::Event(int c, const char *t) // constructeur d'initialisation
{
	setCode(c);
	currentCode = c;
	title = nullptr;
	setTitle(t);
}

Event::Event(const Event &e) // copie d'un objet et on veut pas de modification
{
	setCode(e.getCode());
	title = nullptr;
	setTitle(e.getTitle());
	timing = nullptr;
	setTiming(e.getTiming());
}

Event::~Event() // desctructeur
{
	if (title) delete title;
	if (timing) delete timing;
}

void Event::setCode(int c)
{
	if(c <= 0) return;
	code = c;
}

void Event::setTitle(const char *t)
{
	if (title) delete title;
	title = new char[strlen(t) + 1];
	strcpy(title, t);
}

void Event::setTiming(const Timing& t)
{
	timing = new Timing(t);
}

int Event::getCode() const
{
	return code;
}

const char * Event::getTitle() const // on précise par le const (avant) que ce qui est retourner ne doit pas être modifier de l'extérieure
{
	return title;
}

Timing Event::getTiming() const
{
	return *timing;
}

void Event::display() const
{
	cout << "Event (" << code << ") :" << title << endl;
	if (!timing) return;
	timing->display();
}

}