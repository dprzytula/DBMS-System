#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <QDebug>
#include "ROT13.h"

using namespace std;

struct Book {
	int idBook;
	int idAuthorFK;
	int idGenreFK;
	int idPublisherFK;
	string title;
};

extern string line;
extern ofstream myFile;
void saveBookToFile(int idBook, int idAuthorFK, int idGenreFK, int idPublisherFK, string title, bool append);
Book addBook2(int idBook,int idAuthorFK, int idGenreFK, int idPublisherFK, string title);
Book addBook(int idBook, int idAuthor, int idGenre, int idPublisher, string title);

