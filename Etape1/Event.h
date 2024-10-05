// Fichier .h :
// déclaration de la classe et la déclaration des méthodes dedans

#ifndef EVENT_H // si la macro n'est pas définie, je la défini
#define EVENT_H

class Event
{
private:
	int code;
	char* title;
public:
	Event();
	Event(int c, const char *t);
	Event(const Event &e);
	~Event();

	void setCode(int c);
	void setTitle(const char *t);
	int getCode() const;
	const char * getTitle() const;
	void display() const;
};
#endif