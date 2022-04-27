#include "CopyOfBook.h"

void saveCopyToFile(int idCopyOfBook, int idBookFK, string ISBN, bool append) {
	Cipher cipher;
	ofstream myfile;

	if (append) {
		myfile.open("cobTable.dat", ios::out | ios::app | ios::binary);
	}
	else {
		myfile.open("cobTable.dat", ios::out | ios::binary);
	}

	string line = "|" + to_string(idCopyOfBook) + "|" + to_string(idBookFK) + "|" + ISBN + "|";

	line = cipher.encrypt(line);
	myfile << line << endl;
	myfile.close();
}

CopyOfBook addCopy()
{
	CopyOfBook cob;
	cout << "Podaj id Egzemplarza " << endl;
	cin >> cob.idCopyOfBook;
	cout << "Podaj id Ksiazki " << endl;
	cin >> cob.idBookFK;
	cout << "Podaj kod ISBN ksiazki " << endl;
	cin >> cob.ISBN;
	
	saveCopyToFile(cob.idCopyOfBook, cob.idBookFK, cob.ISBN, true);

	return cob;
}

CopyOfBook addCopy(int idCopyOfBook, int idBookFK, string ISBN)
{
	CopyOfBook cob;

	cob.idCopyOfBook = idCopyOfBook;
	cob.idBookFK = idCopyOfBook;
	cob.ISBN = ISBN;

	return cob;
}

void displayCopyOfBook(CopyOfBook cob) {
	cout << "ID: " << cob.idCopyOfBook << " | Id Book: " << cob.idBookFK << " | Code ISBN: " << cob.ISBN;
}






