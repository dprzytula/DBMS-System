#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "ROT13.h"

using namespace std;

struct Author {
	int idAuthor;
	string firstName;
	string lastName;
};

void saveAuthorToFile(int idAuthor, string firstName, string lastName, bool append);
Author addAuthor();
Author addAuthor(int idAuthor, string firstName, string lastName);
void displayAuthor(Author author);

