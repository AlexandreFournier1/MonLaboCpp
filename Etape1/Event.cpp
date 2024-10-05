#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;

#include "Event.h"

Event::Event() // constructeur par défaut
{
	setCode(1);
	title = nullptr;
	setTitle("default");
}

Event::Event(int c, const char *t) // constructeur d'initialisation
{
	setCode(c);
	title = nullptr;
	setTitle(t);
}

Event::Event(const Event &e) // copie d'un objet et on veut pas de modification
{
	setCode(e.getCode());
	title = nullptr;
	setTitle(e.getTitle());
}

Event::~Event() // desctructeur
{
	if (title) delete title;
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

int Event::getCode() const
{
	return code;
}

const char * Event::getTitle() const // on précise par le const (avant) que ce qui est retourner ne doit pas être modifier de l'extérieure
{
	return title;
}

void Event::display() const
{
	cout << "Event (" << code << ") :" << title << endl;
}