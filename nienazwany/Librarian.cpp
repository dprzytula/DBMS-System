#include "Librarian.h"


Librarian addLibrarian()
{
	Librarian l;
	cout << "Podaj id bibliotekarza " << endl;
	cin >> l.idLibrarian;
	cout << "Podaj imie bibliotekarza " << endl;
	cin >> l.firstName;
	cout << "Podaj nazwisko bibliotekarza " << endl;
	cin >> l.lastName;
	cout << "Podaj datê urodzenia bibliotekarza " << endl;
	cin >> l.dateOfBirth;
	cout << "Podaj numer telefonu bibliotekarza " << endl;
	cin >> l.numberOfPhone;
	cout << "Podaj pensjê bibliotekarza " << endl;
	cin >> l.salary;

	ofstream myfile;
	myfile.open("librarianTable.txt", ios::out | ios::app);
	myfile << "|" << l.idLibrarian << "|" << l.firstName << "|" << l.lastName << "|" << l.dateOfBirth << "|" << l.numberOfPhone << "|" << l.salary << "|" << endl;
	myfile.close();

	return l;
}

Librarian addLibrarian(int idLibrarian, string firstName, string lastName, string dateOfBirth, string numberOfPhone, double salary)
{
	Librarian l;

	l.idLibrarian = idLibrarian;
	l.firstName = firstName;
	l.lastName = lastName;
	l.dateOfBirth = dateOfBirth;
	l.numberOfPhone = numberOfPhone;
	l.salary = salary;

	return l;
}

void displayLibrarian(Librarian l) {
	cout << "ID: " << l.idLibrarian << " | First Name: " << l.firstName << " | Last Name: " << l.lastName << " | Date of birth: " << l.dateOfBirth << " | Number of Phone: " << l.numberOfPhone << " | Salary: " << l.salary << endl;
}

