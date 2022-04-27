#pragma once
#include <iostream>
#include <list>
#include "Author.h"
#include "Genre.h"
#include "Publisher.h"
#include "Book.h"
#include "CopyOfBook.h"
#include "Rental.h"
#include "Reader.h"
#include "Librarian.h"

using namespace std;

class Database {
private:
	list <Author> tableAuthor;
	list <Genre> tableGenre;
	list <Publisher> tablePublisher;
	list <Book> tableBook;
	list <CopyOfBook> tableCopyOfBook;
	list <Rental> tableRental;
	list <Reader> tableReader;
	list <Librarian> tableLibrarian;
public:
	void pushAuthor(Author author);
	void pushGenre(Genre genre);
	void pushPublisher(Publisher publisher);
	void pushBook(Book book);
	void pushReader(Reader reader);
	void pushCopyOfBook(CopyOfBook copyofbook);

	void showAuthorList();
	void showGenreList();
	void showPublisherList();
	void showBookList();
	void showReaderList();
	void showCopyOfBooksList();

	bool authorExist(int id);
	bool genreExist(int id);
	bool publisherExist(int id);

	Author getAuthor(int id);
	Genre getGenre(int id);
	Publisher getPublisher(int id);

	list <Author> getTableOfAuthors();
	list <Genre> getTableOfGenres();
	list <Publisher> getTableOfPublishers();
	list <Book> getTableOfBooks();
	list <CopyOfBook> getTableOfCopies();
	list <Rental> getTableOfRentals();
	list <Reader> getTableOfReaders();
	list <Librarian> getTableOfLibrarians();

	void setTableOfAuthors(list <Author> tableOfAuthors);
	void setTableOfGenres(list <Genre> tableOfGenres);
	void setTableOfPublishers(list <Publisher> tableOfPublishers);
	void setTableOfBooks(list <Book> tableOfBooks);
	void setTableOfCopies(list <CopyOfBook> tableOfCopies);
};