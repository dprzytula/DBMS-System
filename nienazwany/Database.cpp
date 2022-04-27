#include "Database.h"

void Database::pushAuthor(Author author)
{

	tableAuthor.push_back(author);
}

void Database::pushGenre(Genre genre)
{

	tableGenre.push_back(genre);
}

void Database::pushPublisher(Publisher publisher)
{

	tablePublisher.push_back(publisher);
}

void Database::pushBook(Book book)
{
	/*if (authorExist(book.idAuthorFK) && genreExist(book.idGenreFK) && publisherExist(book.idPublisherFK))
	{
		tableBook.push_back(book);
	}
	else
	{
		cout << "One of given foreign keys does not exist!";
	}*/

	tableBook.push_back(book);
}

void Database::pushReader(Reader reader)
{
	tableReader.push_back(reader);
}

void Database::pushCopyOfBook(CopyOfBook copyofbook)
{
	tableCopyOfBook.push_back(copyofbook);
}

void Database::showReaderList()
{
	for (std::list<Reader>::iterator it = tableReader.begin(); it != tableReader.end(); ++it)
	{
		displayReader(*it);
		cout << endl;
	}
}

void Database::showCopyOfBooksList()
{
	for (std::list<CopyOfBook>::iterator it = tableCopyOfBook.begin(); it != tableCopyOfBook.end(); ++it)
	{
		displayCopyOfBook(*it);
		cout << endl;
	}
}

void Database::showAuthorList()
{
	for (std::list<Author>::iterator it = tableAuthor.begin(); it != tableAuthor.end(); ++it) {
		displayAuthor(*it);
		cout << endl;
	}
}

void Database::showGenreList()
{
	for (std::list<Genre>::iterator it = tableGenre.begin(); it != tableGenre.end(); ++it) {
		displayGenre(*it);
		cout << endl;
	}
}

void Database::showPublisherList()
{
	for (std::list<Publisher>::iterator it = tablePublisher.begin(); it != tablePublisher.end(); ++it) {
		displayPublisher(*it);
		cout << endl;
	}
}

void Database::showBookList()
{
	Book b;

	for (std::list<Book>::iterator it = tableBook.begin(); it != tableBook.end(); ++it) {
		b = *it;

		cout << "ID: " << b.idBook << " | " << "Title: " << b.title << endl;
		/*displayAuthor(getAuthor(b.idAuthorFK));
		cout << endl;
		displayGenre(getGenre(b.idGenreFK));
		cout << endl;
		displayPublisher(getPublisher(b.idPublisherFK));
		cout << endl;*/
	}
}

bool Database::authorExist(int id)
{
	for (std::list<Author>::iterator it = tableAuthor.begin(); it != tableAuthor.end(); ++it) {
		int idTemp = it->idAuthor;
		if (idTemp == id) {
			return true;
		}
	}

	return false;
}

bool Database::genreExist(int id)
{
	for (std::list<Genre>::iterator it = tableGenre.begin(); it != tableGenre.end(); ++it) {
		int idTemp = it->idGenre;
		if (idTemp == id) {
			return true;
		}
	}

	return false;
}

bool Database::publisherExist(int id)
{
	for (std::list<Publisher>::iterator it = tablePublisher.begin(); it != tablePublisher.end(); ++it) {
		int idTemp = it->idPublisher;
		if (idTemp == id) {
			return true;
		}
	}

	return false;
}

Author Database::getAuthor(int id)
{
	for (std::list<Author>::iterator it = tableAuthor.begin(); it != tableAuthor.end(); ++it) {
		int idTemp = it->idAuthor;
		if (idTemp == id) {
			return *it;
		}
	}
}

Genre Database::getGenre(int id)
{
	for (std::list<Genre>::iterator it = tableGenre.begin(); it != tableGenre.end(); ++it) {
		int idTemp = it->idGenre;
		if (idTemp == id) {
			return *it;
		}
	}
}

Publisher Database::getPublisher(int id)
{
	for (std::list<Publisher>::iterator it = tablePublisher.begin(); it != tablePublisher.end(); ++it) {
		int idTemp = it->idPublisher;
		if (idTemp == id) {
			return *it;
		}
	}
}

list <Author> Database::getTableOfAuthors()
{
	list <Author> table;

	for (std::list<Author>::iterator it = tableAuthor.begin(); it != tableAuthor.end(); ++it) {
		table.push_back(*it);
	}

	return table;
}

list <Genre> Database::getTableOfGenres()
{
	list <Genre> table;

	for (std::list<Genre>::iterator it = tableGenre.begin(); it != tableGenre.end(); ++it) {
		table.push_back(*it);
	}

	return table;
}

list <Publisher> Database::getTableOfPublishers()
{
	list <Publisher> table;

	for (std::list<Publisher>::iterator it = tablePublisher.begin(); it != tablePublisher.end(); ++it) {
		table.push_back(*it);
	}

	return table;
}

list <Book> Database::getTableOfBooks()
{
	list <Book> table;

	for (std::list<Book>::iterator it = tableBook.begin(); it != tableBook.end(); ++it) {
		table.push_back(*it);
	}

	return table;
}

list <CopyOfBook> Database::getTableOfCopies()
{
	list <CopyOfBook> table;

	for (std::list<CopyOfBook>::iterator it = tableCopyOfBook.begin(); it != tableCopyOfBook.end(); ++it) {
		table.push_back(*it);
	}

	return table;
}

list <Rental> Database::getTableOfRentals()
{
	list <Rental> table;

	for (std::list<Rental>::iterator it = tableRental.begin(); it != tableRental.end(); ++it) {
		table.push_back(*it);
	}

	return table;
}

list <Reader> Database::getTableOfReaders()
{
	list <Reader> table;

	for (std::list<Reader>::iterator it = tableReader.begin(); it != tableReader.end(); ++it) {
		table.push_back(*it);
	}

	return table;
}

list <Librarian> Database::getTableOfLibrarians()
{
	list <Librarian> table;

	for (std::list<Librarian>::iterator it = tableLibrarian.begin(); it != tableLibrarian.end(); ++it) {
		table.push_back(*it);
	}

	return table;
}

void Database::setTableOfAuthors(list <Author> tableOfAuthors) {
	this->tableAuthor = tableOfAuthors;
}

void Database::setTableOfGenres(list <Genre> tableOfGenres) {
	this->tableGenre = tableOfGenres;
}

void Database::setTableOfPublishers(list <Publisher> tableOfPublishers) {
	this->tablePublisher = tableOfPublishers;
}

void Database::setTableOfBooks(list <Book> tableOfBooks) {
	this->tableBook = tableOfBooks;
}

void Database::setTableOfCopies(list <CopyOfBook> tableOfCopies) {
	this->tableCopyOfBook = tableOfCopies;;
}