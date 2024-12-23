#include "XmlFileSerializer.hpp"

template <typename T>
char const XmlFileSerializer<T>::READ = 'R';

template <typename T>
char const XmlFileSerializer<T>::WRITE = 'W';

template <typename T>
XmlFileSerializer<T>::XmlFileSerializer(const string &fn, char m, const string& cn)
{
	if(m == WRITE)
	{	
		file.open(fn, ios::out | ios::trunc);
		if(!file.is_open())
		{
			// Erreur d'ouverture
		}

		file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
		file << "<" << cn << ">" << endl;
	}

	else if (m == READ)
	{
		file.open(fn, ios::in);
		if(!file.is_open())
		{
			// Erreur d'ouverture
		}

		string line;
		getline(file, line); // En-tête XML

		getline(file, line); // Balise de début de collection

		collectionName = line.substr(1, line.size() - 2);
	}
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

template <typename T>
XmlFileSerializer<T>::~XmlFileSerializer() 
{
    if (file.is_open()) 
    {
        if (mode == WRITE) 
        {
            file << "</" << collectionName << ">\n";
        }

        file.close();
    }
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

template <typename T>
string XmlFileSerializer<T>::getFilename() 
{
    return filename;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

template <typename T>
string XmlFileSerializer<T>::getCollectionName() 
{
    return collectionName;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

template <typename T>
bool XmlFileSerializer<T>::isReadable() 
{
    return mode == READ && file.is_open();
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

template <typename T>
bool XmlFileSerializer<T>::isWritable() 
{
    return mode == WRITE && file.is_open();
}