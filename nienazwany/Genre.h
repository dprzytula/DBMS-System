#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "ROT13.h"

using namespace std;

struct Genre {
	int idGenre;
	string name;
};

extern ofstream myFile;
extern string line2;
void saveGenreToFile(int idGenre, string name, bool append);
Genre addGenre();
Genre addGenre(int idGenre, string name);
void displayGenre(Genre genre);
