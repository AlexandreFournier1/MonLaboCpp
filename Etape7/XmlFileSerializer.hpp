#ifndef XMLFILESERIALIZER_HPP
#define XMLFILESERIALIZER_HPP

template<typename T>
class XmlFileSerializer 
{
	friend ostream& operator<<(ostream& s, const T& val);
	friend istream& operator>>(istream& s, T& val);

private:
	fstream file;
	string filename;
	char mode;
	string collectionName;
public:
	XmlFileSerializer() delete;
	XmlFileSerializer(const XmlFileSerializer& x) delete;
	XmlFileSerializer(const string &fn, char m, const string& cn = "entities");
	~XmlFileSerializer();

	string getFilename();
	string getCollectionName();
	bool isReadable();
	bool isWritable();

	XmlFileSerializer& operator=(const XmlFileSerializer& x) delete;

	void write(const T& val);
	T read();

	static string const READ, WRITE;
}

#include "XmlFileSerializer.ipp"

#endif