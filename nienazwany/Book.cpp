#include "Book.h"

void saveBookToFile(int idBook, int idAuthorFK, int idGenreFK, int idPublisherFK, string title, bool append) {
    Cipher cipher;
    ofstream myfile;
    if (append) {
        myfile.open("C:\\Users\\dando\\Documents\\nienazwany\\bookTable.dat", ios::out | ios::app | ios::binary);
    }
    else {
        myfile.open("C:\\Users\\dando\\Documents\\nienazwany\\bookTable.dat", ios::out | ios::binary);
    }

    string line = "|" + to_string(idBook) + "|" + to_string(idAuthorFK) + "|" + to_string(idGenreFK) + "|" + to_string(idPublisherFK) + "|" + title + "|";

    line = cipher.encrypt(line);
    myfile<< line << endl;
    myfile.close();
}

Book addBook(int idBook, int idAuthor, int idGenre, int idPublisher, string title)
{
    Book b;

    b.idBook = idBook;
    b.idAuthorFK = idAuthor;
    b.idGenreFK = idGenre;
    b.idPublisherFK = idPublisher;
    b.title = title;

    return b;
}

Book addBook2(int idBook,int idAuthorFK, int idGenreFK, int idPublisherFK, string title)
{
    Book b;
    b.idBook = idBook;
    b.idAuthorFK = idAuthorFK;
    b.idGenreFK = idGenreFK;
    b.idPublisherFK = idPublisherFK;
    b.title = title;
    qDebug()<<"witam";
    saveBookToFile(b.idBook, b.idAuthorFK, b.idGenreFK, b.idPublisherFK, b.title, true);

    return b;
}


