#include "Reader.h"


Reader addReader()
{
	Reader r;
	cout << "Podaj id Czytelnika " << endl;
	cin >> r.idReader;
	cout << "Podaj imie Czytelnika " << endl;
	cin >> r.firstName;
	cout << "Podaj nazwisko Czytelnika " << endl;
	cin >> r.lastName;
	cout << "Podaj date urodzin Czytelnika " << endl;
	cin >> r.dateOfBirth;
	cout << "Podaj numer telefonu Czytelnika " << endl;
	cin >> r.numberOfPhone;

	Cipher cipher;
	ofstream myfile("readerTable.dat", ios::out | ios::app | ios::binary);
	string line = "|" + to_string(r.idReader) + "|" + (r.firstName) + "|" + (r.lastName) + "|" + (r.dateOfBirth) + "|" + (r.numberOfPhone) + "|";
	
	line = cipher.encrypt(line);
	myfile << line << endl;
	myfile.close();


	return r;
}

Reader addReaderaddReader(int idReader, string firstName, string lastName, string dateOfBirth, string numberOfPhone)
{
	Reader r;
	r.idReader = idReader;
	r.firstName = firstName;
	r.firstName = firstName;
	r.lastName = lastName;
	r.dateOfBirth = dateOfBirth;
	r.numberOfPhone = numberOfPhone;

	return r;
}

void displayReader(Reader r) {
	cout << "ID: " << r.idReader << " | First Name: " << r.firstName << " | Last Name: " << r.lastName << "| Date of Birth: " << r.dateOfBirth << "| NumberOfPhone: " << r.numberOfPhone;

}

