#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Rental {
	int idRental;
	int idReaderFK;
	int idCopyOfBookFK;
	int idLibrarianFK;
	string dateOfRent;
	string dateOfReturn;
};

Rental addRental();
Rental addRental(int idRental, int idReaderFK, int idCopyOfBookFK, int idLibrarianFK, string dateOfRent, string dateOfReturn);
void displayRental(Rental rental);

