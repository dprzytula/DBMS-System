#include "Author.h"

void saveAuthorToFile(int idAuthor, string firstName, string lastName, bool append) {
	Cipher cipher;
	ofstream myfile;

	if (append) {
		myfile.open("authorTable.dat", ios::out | ios::app | ios::binary);
	}
	else {
		myfile.open("authorTable.dat", ios::out | ios::binary);
	}

	string line = "|" + to_string(idAuthor) + "|" + firstName + "|" + lastName + "|";

	line = cipher.encrypt(line);
	myfile << line << endl;
	myfile.close();
}

Author addAuthor()
{
	Author a;
	cout << "Podaj id Autora " << endl;
	cin >> a.idAuthor;
	cout << "Podaj imie Autora " << endl;
	cin >> a.firstName;
	cout << "Podaj nazwisko Autora " << endl;
	cin >> a.lastName;

	saveAuthorToFile(a.idAuthor, a.firstName, a.lastName, true);

	return a;
}

Author addAuthor(int idAuthor, string firstName, string lastName)
{
	Author a;

	a.idAuthor = idAuthor;
	a.firstName = firstName;
	a.lastName = lastName;

	return a;
}

void displayAuthor(Author a) {
	cout << "ID: " << a.idAuthor << " | First Name: " << a.firstName << " | Last Name: " << a.lastName;
}

