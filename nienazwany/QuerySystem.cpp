#include "QuerySystem.h"

// SELECT * FROM Book;
// SELECT, DELETE, UPDATE, INSERT
void QuerySystem::executeQuery(string query, Database *db, list<QMap<QString, QString>> *results) {
    int operationID;

    for (int i = 0; i < query.length(); i++) {
        query[i] = tolower(query[i]); // przekonwertowanie stringa na male litery
    }

    if ((operationID = query.find("select")) == string::npos) {
        if ((operationID = query.find("delete")) == string::npos) {
            if ((operationID = query.find("update")) == string::npos) {
                if ((operationID = query.find("insert into")) == string::npos) {
                    cout << "The given query does not have any specified operation!" << endl; // sprawdzenie czy wpisano operacje (select, delete, update)
                    return;
                }
                else {
                    //doInsert(query, operationID, db);
                }
            }
            else {
                //doUpdate(query, operationID, db);
            }
        }
        else {
            //doDelete(query, operationID, db);
        }
    }
    else {
        doSelect(query, operationID, db, results);
    }
}

void QuerySystem::doSelect(string query, int operationID, Database* db, list<QMap<QString, QString>> *results) {
    int fromID = query.find("FROM");
    int semicolonID = query.find(";");

    if ((fromID = query.find("from")) == string::npos) {
        cout << "The given query does not have \"FROM\" keyword!" << endl; // sprawdzenie czy istnieje slowo from
        return;
    }

    if ((semicolonID = query.find(";")) == string::npos) {
        cout << "The given query does not have \";\" character!" << endl; // sprawdzenie czy istnieje srednik
        return;
    }

    QString arguments = QString::fromStdString(string(query.begin() + operationID + 6, query.begin() + fromID));
    QString table = QString::fromStdString(string(query.begin() + fromID + 4, query.begin() + semicolonID));

    arguments.replace(" ","");
    table.replace(" ","");

    QVector<int> argumentsID;
    QVector<QString> argumentNames;

    if (arguments.compare("*") != 0) {
        argumentsID.push_back(arguments.indexOf(","));
        while (argumentsID.back() != string::npos) {
            argumentsID.push_back(arguments.indexOf(",", argumentsID.back() + 1));
        }
        argumentsID.pop_back();

        if (!argumentsID.empty()) {
            int temp = argumentsID.front();
            argumentNames.push_back(arguments.mid(0, 0 + temp));
            for (QVector<int>::iterator it = argumentsID.begin(); it != argumentsID.end(); ++it) {
                if (*it == temp) {
                    continue;
                }

                argumentNames.push_back(arguments.mid(temp + 1, *it - temp - 1));
                temp = *it;
            }
            argumentNames.push_back(arguments.mid(0 + temp + 1, arguments.length()));
        }
        else {
            argumentNames.push_back(arguments);
        }
    }
    else {
        if (table.compare("author") == 0) {
            db->showAuthorList();
        }
        else if (table.compare("genre") == 0) {
            db->showGenreList();
        }
        else if (table.compare("publisher") == 0) {
            db->showPublisherList();
        }
        else if (table.compare("book") == 0) {
            db->showBookList();
        }
        else if (table.compare("copyofbook") == 0) {
            db->showCopyOfBooksList();
        }
        else if (table.compare("reader") == 0) {
            db->showReaderList();
        }

        return;
    }

    QMap<QString, QString> result;

    if (table.compare("author") == 0) {
        list <Author> table = db->getTableOfAuthors();
        Author author;

        for (list<Author>::iterator it = table.begin(); it != table.end(); ++it) {
            author = *it;

            for (QVector<QString>::iterator it2 = argumentNames.begin(); it2 != argumentNames.end(); ++it2) {
                if (QString("idauthor").compare(*it2) == 0) {
                    result.insert(QString::fromStdString("idAuthor"), QString::number(author.idAuthor));
                }
                else if (QString("firstname").compare(*it2) == 0) {
                    result.insert(QString::fromStdString("Firstname"), QString::fromStdString(author.firstName));
                }
                else if (QString("lastname").compare(*it2) == 0) {
                    result.insert(QString::fromStdString("Lastname"), QString::fromStdString(author.lastName));
                }
            }

            results->push_back(result);
            result.clear();
        }
    }
    else if (table.compare("genre") == 0) {
        list <Genre> table = db->getTableOfGenres();
        Genre genre;

        for (list<Genre>::iterator it = table.begin(); it != table.end(); ++it) {
            genre = *it;

            for (QVector<QString>::iterator it2 = argumentNames.begin(); it2 != argumentNames.end(); ++it2) {
                if (QString("idgenre").compare(*it2) == 0) {
                    result.insert(QString::fromStdString("idGenre"), QString::number(genre.idGenre));
                }
                else if (QString("name").compare(*it2) == 0) {
                    result.insert(QString::fromStdString("Name"), QString::fromStdString(genre.name));
                }
            }

            results->push_back(result);
            result.clear();
        }
    }
    else if (table.compare("publisher") == 0) {
        list <Publisher> table = db->getTableOfPublishers();
        Publisher publisher;

        for (list<Publisher>::iterator it = table.begin(); it != table.end(); ++it) {
            publisher = *it;

            for (QVector<QString>::iterator it2 = argumentNames.begin(); it2 != argumentNames.end(); ++it2) {
                if (QString("idpublisher").compare(*it2) == 0) {
                    result.insert(QString::fromStdString("idPublisher"), QString::number(publisher.idPublisher));
                }
                else if (QString("name").compare(*it2) == 0) {
                    result.insert(QString::fromStdString("Name"), QString::fromStdString(publisher.name));
                }
            }

            results->push_back(result);
            result.clear();
        }
    }
    else if (table.compare("book") == 0) {
        list <Book> table = db->getTableOfBooks();
        Book book;

        for (list<Book>::iterator it = table.begin(); it != table.end(); ++it) {
            book = *it;

            for (QVector<QString>::iterator it2 = argumentNames.begin(); it2 != argumentNames.end(); ++it2) {
                if (QString("idbook").compare(*it2) == 0) {
                    result.insert(QString::fromStdString("idBook"), QString::number(book.idBook));
                }
                else if (QString("idauthorfk").compare(*it2) == 0) {
                    result.insert(QString::fromStdString("idAuthorFK"), QString::number(book.idAuthorFK));
                }
                else if (QString("idgenrefk").compare(*it2) == 0) {
                    result.insert(QString::fromStdString("idGenreFK"), QString::number(book.idGenreFK));
                }
                else if (QString("idpublisherfk").compare(*it2) == 0) {
                    result.insert(QString::fromStdString("idPublisherFK"), QString::number(book.idPublisherFK));
                }
                else if (QString("title").compare(*it2) == 0) {
                    result.insert(QString::fromStdString("Title"), QString::fromStdString(book.title));
                }
            }

            results->push_back(result);
            result.clear();
        }
    }
    else if (table.compare("copyofbook") == 0) {
        list <CopyOfBook> table = db->getTableOfCopies();
        CopyOfBook cob;

        for (list<CopyOfBook>::iterator it = table.begin(); it != table.end(); ++it) {
            cob = *it;
            
            for (QVector<QString>::iterator it2 = argumentNames.begin(); it2 != argumentNames.end(); ++it2) {
                if (QString("idcopyofbook").compare(*it2) == 0) {
                    result.insert(QString::fromStdString("idCopyOfBook"), QString::number(cob.idCopyOfBook));
                }
                else if (QString("idbookfk").compare(*it2) == 0) {
                    result.insert(QString::fromStdString("idBookFK"), QString::number(cob.idBookFK));
                }
                else if (QString("isbn").compare(*it2) == 0) {
                    result.insert(QString::fromStdString("ISBN"), QString::fromStdString(cob.ISBN));
                }
            }

            results->push_back(result);
            result.clear();
        }
    }
    else if (table.compare("reader") == 0) {
        list <Reader> table = db->getTableOfReaders();
        Reader reader;

        for (list<Reader>::iterator it = table.begin(); it != table.end(); ++it) {
            reader = *it;

            for (QVector<QString>::iterator it2 = argumentNames.begin(); it2 != argumentNames.end(); ++it2) {
                if (QString("idreader").compare(*it2) == 0) {
                    result.insert(QString::fromStdString("idReader"), QString::number(reader.idReader));
                }
                else if (QString("firstname").compare(*it2) == 0) {
                    result.insert(QString::fromStdString("FirstName"), QString::fromStdString(reader.firstName));
                }
                else if (QString("lastname").compare(*it2) == 0) {
                    result.insert(QString::fromStdString("LastName"), QString::fromStdString(reader.lastName));
                }
                else if (QString("dateofbirth").compare(*it2) == 0) {
                    result.insert(QString::fromStdString("DateOfBirth"), QString::fromStdString(reader.dateOfBirth));
                }
                else if (QString("numberofphone").compare(*it2) == 0) {
                    result.insert(QString::fromStdString("NumberOfPhone"), QString::fromStdString(reader.numberOfPhone));
                }
            }

            results->push_back(result);
            result.clear();
        }
    }
    return;
}

/*bool QuerySystem::doDelete(string query, int operationID, Database* db) {
    int fromID = query.find("FROM");
    int whereID = query.find("WHERE");
    int idID = query.find("id");
    int eqID = query.find("=");
    int semicolonID = query.find(";");

    if ((fromID = query.find("from")) == string::npos) {
        cout << "The given query does not have \"FROM\" keyword!" << endl;
        return false;
    }

    if ((whereID = query.find("where")) == string::npos) {
        cout << "The given query does not have \"WHERE\" keyword!" << endl;
        return false;
    }

    if ((idID = query.find("id")) == string::npos) {
        cout << "The given query does not have \"id\" keyword!" << endl;
        return false;
    }

    if ((eqID = query.find("=")) == string::npos) {
        cout << "The given query does not have \"=\" character!" << endl;
        return false;
    }

    if ((semicolonID = query.find(";")) == string::npos) {
        cout << "The given query does not have \";\" character!" << endl;
        return false;
    }

    string table = string(query.begin() + fromID + 4, query.begin() + whereID);
    string id = string(query.begin() + eqID + 1, query.begin() + semicolonID);

    table.erase(remove_if(table.begin(), table.end(), isspace), table.end());
    id.erase(remove_if(id.begin(), id.end(), isspace), id.end());

    if (table.compare("author") == 0) {
        list <Author> table = db->getTableOfAuthors();
        list <Book> table2 = db->getTableOfBooks();
        Author author;
        Book book;

        for (list<Book>::iterator it = table2.begin(); it != table2.end(); ++it) {
            book = *it;

            if (book.idAuthorFK == stoi(id)) {
                cout << "A record with this ID has occurencies in Book table! Try to delete this records first." << endl;
                return false;
            }
        }

        for (list<Author>::iterator it = table.begin(); it != table.end(); ++it) {
            author = *it;

            if (author.idAuthor == stoi(id)) {
                table.erase(it);
                break;
            }
        }

        db->setTableOfAuthors(table);

        author = table.front();
        int idAuthor = author.idAuthor;
        for (list<Author>::iterator it = table.begin(); it != table.end(); ++it) {
            author = *it;

            if (author.idAuthor == idAuthor) {
                saveAuthorToFile(author.idAuthor, author.firstName, author.lastName, false);
            }
            else {
                saveAuthorToFile(author.idAuthor, author.firstName, author.lastName, true);
            }
        }
    }
    else if (table.compare("genre") == 0) {
        list <Genre> table = db->getTableOfGenres();
        list <Book> table2 = db->getTableOfBooks();
        Genre genre;
        Book book;

        for (list<Book>::iterator it = table2.begin(); it != table2.end(); ++it) {
            book = *it;

            if (book.idGenreFK == stoi(id)) {
                cout << "A record with this ID has occurencies in Book table! Try to delete this records first." << endl;
                return false;
            }
        }

        for (list<Genre>::iterator it = table.begin(); it != table.end(); ++it) {
            genre = *it;

            if (genre.idGenre == stoi(id)) {
                table.erase(it);
                break;
            }
        }

        db->setTableOfGenres(table);

        genre = table.front();
        int idGenre = genre.idGenre;
        for (list<Genre>::iterator it = table.begin(); it != table.end(); ++it) {
            genre = *it;

            if (genre.idGenre == idGenre) {
                saveGenreToFile(genre.idGenre, genre.name, false);
            }
            else {
                saveGenreToFile(genre.idGenre, genre.name, true);
            }
        }
    }
    else if (table.compare("publisher") == 0) {
        list <Publisher> table = db->getTableOfPublishers();
        list <Book> table2 = db->getTableOfBooks();
        Publisher publisher;
        Book book;

        for (list<Book>::iterator it = table2.begin(); it != table2.end(); ++it) {
            book = *it;

            if (book.idPublisherFK == stoi(id)) {
                cout << "A record with this ID has occurencies in Book table! Try to delete this records first." << endl;
                return false;
            }
        }

        for (list<Publisher>::iterator it = table.begin(); it != table.end(); ++it) {
            publisher = *it;

            if (publisher.idPublisher == stoi(id)) {
                table.erase(it);
                break;
            }
        }

        db->setTableOfPublishers(table);

        publisher = table.front();
        int idPublisher = publisher.idPublisher;
        for (list<Publisher>::iterator it = table.begin(); it != table.end(); ++it) {
            publisher = *it;

            if (publisher.idPublisher == idPublisher) {
                savePublisherToFile(publisher.idPublisher, publisher.name, false);
            }
            else {
                savePublisherToFile(publisher.idPublisher, publisher.name, true);
            }
        }
    }
    else if (table.compare("book") == 0) {
        list <Book> table = db->getTableOfBooks();
        list <CopyOfBook> table2 = db->getTableOfCopies();
        Book book;
        CopyOfBook copy;

        for (list<CopyOfBook>::iterator it = table2.begin(); it != table2.end(); ++it) {
            copy = *it;

            if (copy.idBookFK == stoi(id)) {
                cout << "A record with this ID has occurencies in CopyOfBooks table! Try to delete this records first." << endl;
                return false;
            }
        }

        for (list<Book>::iterator it = table.begin(); it != table.end(); ++it) {
            book = *it;

            if (book.idBook == stoi(id)) {
                table.erase(it);
                break;
            }
        }

        db->setTableOfBooks(table);

        if (!table.empty()) {
            book = table.front();
            int idBook = book.idBook;
            for (list<Book>::iterator it = table.begin(); it != table.end(); ++it) {
                book = *it;

                if (book.idBook == idBook) {
                    saveBookToFile(book.idBook, book.idAuthorFK, book.idGenreFK, book.idPublisherFK, book.title, false);
                }
                else {
                    saveBookToFile(book.idBook, book.idAuthorFK, book.idGenreFK, book.idPublisherFK, book.title, true);
                }
            }
        }
        else {
            clearFile("bookTable.dat");
        }
        
    }
    else if (table.compare("copyofbook") == 0) {
        list <CopyOfBook> table = db->getTableOfCopies();
        list <Rental> table2 = db->getTableOfRentals();
        CopyOfBook cob;
        Rental copy;

        for (list<Rental>::iterator it = table2.begin(); it != table2.end(); ++it) {
            copy = *it;

            if (copy.idCopyOfBookFK == stoi(id)) {
                cout << "A record with this ID has occurencies in Rental table! Try to delete this records first." << endl;
                return false;
            }
        }

        for (list<CopyOfBook>::iterator it = table.begin(); it != table.end(); ++it) {
            cob = *it;

            if (cob.idCopyOfBook == stoi(id)) {
                table.erase(it);
                break;
            }
        }

        db->setTableOfCopies(table);

        cob = table.front();
        int idCopy = cob.idCopyOfBook;
        for (list<CopyOfBook>::iterator it = table.begin(); it != table.end(); ++it) {
            cob = *it;

            if (cob.idCopyOfBook == idCopy) {
                saveCopyToFile(cob.idCopyOfBook, cob.idBookFK, cob.ISBN, false);
            }
            else {
                saveCopyToFile(cob.idCopyOfBook, cob.idBookFK, cob.ISBN, false);
            }
        }
    }

    return true;
}

bool QuerySystem::doInsert(string query, int operationID, Database* db) {
    int valuesID = query.find("VALUES");
    int leftBracketID = query.find("(");
    int rightBracketID = query.find(")");
    int semicolonID = query.find(";");

    if ((valuesID = query.find("values")) == string::npos) {
        cout << "The given query does not have \"VALUES\" keyword!" << endl;
        return false;
    }

    if ((leftBracketID = query.find("(")) == string::npos) {
        cout << "The given query does not have \"(\" character!" << endl;
        return false;
    }

    if ((rightBracketID = query.find(")")) == string::npos) {
        cout << "The given query does not have \")\" character!" << endl;
        return false;
    }

    if ((semicolonID = query.find(";")) == string::npos) {
        cout << "The given query does not have \";\" character!" << endl;
        return false;
    }

    string table = string(query.begin() + 11, query.begin() + valuesID);
    string arguments = string(query.begin() + leftBracketID + 1, query.begin() + rightBracketID);
    table.erase(remove_if(table.begin(), table.end(), isspace), table.end());
    arguments.erase(remove_if(arguments.begin(), arguments.end(), isspace), arguments.end());

    vector<int> argumentsID;
    vector<string> argumentNames;

    argumentsID.push_back(arguments.find(","));
    while (argumentsID.back() != string::npos) {
        argumentsID.push_back(arguments.find(",", argumentsID.back() + 1));
    }
    argumentsID.pop_back();

    int temp = argumentsID.front();
    argumentNames.push_back(string(arguments.begin(), arguments.begin() + temp));
    for (vector<int>::iterator it = argumentsID.begin(); it != argumentsID.end(); ++it) {
        if (*it == temp) {
            continue;
        }
        argumentNames.push_back(string(arguments.begin() + temp + 1, arguments.begin() + (*it)));
        temp = *it;
    }
    argumentNames.push_back(string(arguments.begin() + temp + 1, arguments.end()));

    if (table.compare("book") == 0) {
        if (argumentNames.size() != 5) {
            cout << "Query does not have matching amount of values!" << endl;
            return false;
        }

        if (argumentNames[0].find("'") != string::npos ||
            argumentNames[1].find("'") != string::npos ||
            argumentNames[2].find("'") != string::npos ||
            argumentNames[3].find("'") != string::npos ||
            argumentNames[4].find("'") == string::npos) {
            cout << "One of the parameters is of incorrect type!" << endl;
            return false;
        }

        argumentNames[4].erase(remove(argumentNames[4].begin(), argumentNames[4].end(), '\''), argumentNames[4].end());

        db->pushBook(addBook(stoi(argumentNames[0]), stoi(argumentNames[1]), stoi(argumentNames[2]), stoi(argumentNames[3]), argumentNames[4]));
        cout << "Book added correctly!" << endl;

        saveBookToFile(stoi(argumentNames[0]), stoi(argumentNames[1]), stoi(argumentNames[2]), stoi(argumentNames[3]), argumentNames[4], true);
    }

    return true;
}

void QuerySystem::clearFile(string file) {
    ofstream fileObject(file, ios::out | ios::binary | ios::trunc);
    fileObject << "";
    fileObject.close();
}*/
