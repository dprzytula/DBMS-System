#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Librarian {
	int idLibrarian;
	string firstName;
	string lastName;
	string dateOfBirth;
	string numberOfPhone;
	double salary;
};

Librarian addLibrarian();
Librarian addLibrarian(int idLibrarian, string firstName, string lastName, string dateOfBirth, string numberOfPhone, double salary);
void displayLibrarian(Librarian librarian);

