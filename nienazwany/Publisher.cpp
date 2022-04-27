#include "Publisher.h"

void savePublisherToFile(int idPublisher, string name, bool append) {
	Cipher cipher;
	ofstream myfile;

	if (append) {
		myfile.open("publisherTable.dat", ios::out | ios::app | ios::binary);
	}
	else {
		myfile.open("publisherTable.dat", ios::out | ios::binary);
	}

	string line = "|" + to_string(idPublisher) + "|" + name + "|";

	line = cipher.encrypt(line);
	myfile << line << endl;
	myfile.close();
}

Publisher addPublisher()
{
	Publisher p;
	cout << "Podaj id wydawnictwa " << endl;
	cin >> p.idPublisher;
	cout << "Podaj nazwe wydawnictwa " << endl;
	cin >> p.name;

	savePublisherToFile(p.idPublisher, p.name, true);

	return p;
}

Publisher addPublisher(int idPublisher, string name) {
	Publisher p;

	p.idPublisher = idPublisher;
	p.name = name;

	return p;
}

void displayPublisher(Publisher p) {
	cout << "ID: " << p.idPublisher << " | Name: " << p.name;
}

