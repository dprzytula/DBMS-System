#include "Genre.h"

void saveGenreToFile(int idGenre, string name, bool append) {
	Cipher cipher;
	ofstream myfile;

	if (append) {
		myfile.open("genreTable.dat", ios::out | ios::app | ios::binary);
	}
	else {
		myfile.open("genreTable.dat", ios::out | ios::binary);
	}

	string line = "|" + to_string(idGenre) + "|" + name + "|";

	line = cipher.encrypt(line);
	myfile << line << endl;
	myfile.close();
}

Genre addGenre()
{
	Genre g;
	cout << "Podaj id Gatunku " << endl;
	cin >> g.idGenre;
	cout << "Podaj nazwe Gatunku " << endl;
	cin >> g.name;

	saveGenreToFile(g.idGenre, g.name, true);

	return g;
}

Genre addGenre(int idGenre, string name) {
	Genre g;

	g.idGenre = idGenre;
	g.name = name;

	return g;
}

void displayGenre(Genre g) {
	cout << "ID: " << g.idGenre << " | Name: " << g.name;
}

