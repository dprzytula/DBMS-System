#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "ROT13.h"

using namespace std;

struct Reader {
	int idReader;
	string firstName;
	string lastName;
	string dateOfBirth;
	string numberOfPhone;
};

Reader addReader();
Reader addReader(int idReader, string firstName, string lastName, string dateofBirth, string numberOfPhone);
void displayReader(Reader r);
