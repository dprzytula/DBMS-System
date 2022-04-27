#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "ROT13.h"

using namespace std;

struct CopyOfBook {
	int idCopyOfBook;
	int idBookFK;
	string ISBN;
};

void saveCopyToFile(int idCopyOfBook, int idBookFK, string ISBN, bool append);
CopyOfBook addCopy();
CopyOfBook addCopy(int idCopyOfBook, int idBookFK, string ISBN);
void displayCopyOfBook(CopyOfBook copyofbook);


