#include "DBMS.h"


void includeFileAuthor(Database* db) {
    Cipher cipher;
    int id[4], idAuthor;
    string firstName, lastName, line;
    ifstream myfile("C:\\Users\\dando\\Documents\\nienazwany\\authorTable.dat", ios::in | ios::binary);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            line = cipher.decrypt(line);
            id[0] = line.find("|");
            for (int i = 1; i < 4; i++) {
                id[i] = line.find("|", id[i - 1] + 1);
            }

            idAuthor = stoi(string(line.begin() + id[0] + 1, line.begin() + id[1]));
            firstName = string(line.begin() + id[1] + 1, line.begin() + id[2]);
            lastName = string(line.begin() + id[2] + 1, line.begin() + id[3]);

            db->pushAuthor(addAuthor(idAuthor, firstName, lastName));
        }
        myfile.close();
    }

    else cout << "Unable to open Author file!" << endl;
}

void includeFileGenre(Database* db) {
    Cipher cipher;
    int id[3], idGenre;
    string name, line;
    ifstream myfile("C:\\Users\\dando\\Documents\\nienazwany\\genreTable.dat", ios::in | ios::binary);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            line = cipher.decrypt(line);
            id[0] = line.find("|");
            for (int i = 1; i < 3; i++) {
                id[i] = line.find("|", id[i - 1] + 1);
            }

            idGenre = stoi(string(line.begin() + id[0] + 1, line.begin() + id[1]));
            name = string(line.begin() + id[1] + 1, line.begin() + id[2]);

            db->pushGenre(addGenre(idGenre, name));
        }
        myfile.close();
    }

    else cout << "Unable to open Genre file!" << endl;
}

void includeFilePublisher(Database* db) {
    Cipher cipher;
    int id[3], idPublisher;
    string name, line;
    ifstream myfile("C:\\Users\\dando\\Documents\\nienazwany\\publisherTable.dat", ios::in | ios::binary);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            line = cipher.decrypt(line);
            id[0] = line.find("|");
            for (int i = 1; i < 3; i++) {
                id[i] = line.find("|", id[i - 1] + 1);
            }

            idPublisher = stoi(string(line.begin() + id[0] + 1, line.begin() + id[1]));
            name = string(line.begin() + id[1] + 1, line.begin() + id[2]);

            db->pushPublisher(addPublisher(idPublisher, name));
        }
        myfile.close();
    }

    else cout << "Unable to open Publisher file!" << endl;
}

void includeFileBook(Database* db) {
    Cipher cipher;
    int id[6], idBook, idAuthor, idGenre, idPublisher;
    string line, title;
    ifstream myfile("C:\\Users\\dando\\Documents\\nienazwany\\bookTable.dat", ios::in | ios::binary);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            line = cipher.decrypt(line);
            id[0] = line.find("|");
            for (int i = 1; i < 6; i++) {
                id[i] = line.find("|", id[i - 1] + 1);
            }

            idBook = stoi(string(line.begin() + id[0] + 1, line.begin() + id[1]));
            idAuthor = stoi(string(line.begin() + id[1] + 1, line.begin() + id[2]));
            idGenre = stoi(string(line.begin() + id[2] + 1, line.begin() + id[3]));
            idPublisher = stoi(string(line.begin() + id[3] + 1, line.begin() + id[4]));
            title = string(line.begin() + id[4] + 1, line.begin() + id[5]);

            db->pushBook(addBook(idBook, idAuthor, idGenre, idPublisher, title));
        }
        myfile.close();
    }

    else cout << "Unable to open Book file!" << endl;
}
/*
void includeCopiesOfBooks(Database* db) {
    Cipher cipher;
    int id[4], idCopyOfBook, idBookFK;
    string ISBN, line;
    ifstream myfile("C:\\Users\\Karol\\Desktop\\nienazwany\\cobTable.dat", ios::in | ios::binary);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            line = cipher.decrypt(line);
            id[0] = line.find("|");
            for (int i = 1; i < 4; i++) {
                id[i] = line.find("|", id[i - 1] + 1);
            }

            idCopyOfBook = stoi(string(line.begin() + id[0] + 1, line.begin() + id[1]));
            idBookFK = stoi(string(line.begin() + id[1] + 1, line.begin() + id[2]));
            ISBN = string(line.begin() + id[2] + 1, line.begin() + id[3]);

            db->pushCopyOfBook(addCopy(idCopyOfBook, idBookFK, ISBN));
        }
        myfile.close();
    }

    else cout << "Unable to open CopyOfBook file!" << endl;
}
*/
/*
int main()
{
    Database db;
    QuerySystem qs;
    int choosePoint;

    includeFileAuthor(&db);
    includeFileGenre(&db);
    includeFilePublisher(&db);
    includeFileBook(&db);
    includeCopiesOfBooks(&db);

    for (;;)
        {

            cout << "Wybierz opcje" << endl;
            cout << "1 - dodaj Autor" << endl;
            cout << "2 - wyswietl liste egzemplarzy" << endl;
            cout << "3 - dodaj Kopie" << endl;
            cout << "4 - dodaj ksiazke" << endl;
            cout << "5 - wyswietl liste ksiazek" << endl;
            cout << "6 - wykonaj kwerende" << endl;
            cout << "7 - zakoncz" << endl;

            cin >> choosePoint;

            switch (choosePoint)
            {
            case 1:
                db.pushAuthor(addAuthor());
                break;
            case 2:
                db.showCopyOfBooksList();
                break;
            case 3:
                db.pushCopyOfBook(addCopy());
                break;
            case 4:
                db.pushBook(addBook());
                break;
            case 5:
                db.showBookList();
                break;
            case 6: {
                string query;
                cout << "Podaj zapytanie, ktore chcesz wykonac: " << endl;
                cin.ignore();
                getline(cin, query);

                qs.executeQuery(query, &db);
                break;
            }
            case 7:
                return 0;
                break;
            }



        }








    return 0;
}*/
