#include "Rental.h"


Rental addRental()
{
	Rental r;
	cout << "Podaj id wypozyczenia " << endl;
	cin >> r.idRental;
	cout << "Podaj id czytelnika " << endl;
	cin >> r.idReaderFK;
	cout << "Podaj id egzemplarza " << endl;
	cin >> r.idCopyOfBookFK;
	cout << "Podaj id bibliotekarza " << endl;
	cin >> r.idLibrarianFK;
	cout << "Podaj datê wypo¿yczenia " << endl;
	cin >> r.dateOfRent;
	cout << "Podaj datê zwrotu " << endl;
	cin >> r.dateOfReturn;

	ofstream myfile;
	myfile.open("rentalTable.txt", ios::out | ios::app);
	myfile << "|" << r.idRental << "|" << r.idReaderFK << "|" << r.idCopyOfBookFK << "|" << r.idLibrarianFK << "|" << r.dateOfRent << "|" << r.dateOfReturn << "|" << endl;
	myfile.close();

	return r;
}

Rental addRental(int idRental, int idReaderFK, int idCopyOfBookFK, int idLibrarianFK, string dateOfRent, string dateOfReturn)
{
	Rental r;

	r.idRental = idRental;
	r.idReaderFK = idReaderFK;
	r.idCopyOfBookFK = idCopyOfBookFK;
	r.idLibrarianFK = idLibrarianFK;
	r.dateOfRent = dateOfRent;
	r.dateOfReturn = dateOfReturn;

	return r;
}

void displayRental(Rental r) {
	cout << "ID: " << r.idRental << " | Date Of Rent: " << r.dateOfRent << " | Date Of Return: " << r.dateOfReturn << endl;
}

