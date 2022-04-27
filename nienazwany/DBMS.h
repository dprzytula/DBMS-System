#include <iostream>
#include <list>
#include "ROT13.h"
#include "Database.h"
#include "QuerySystem.h"

using namespace std;

void includeFileBook(Database* db);
void includeFileAuthor(Database* db);
void includeFileGenre(Database* db);
void includeFilePublisher(Database* db);
void includeCopiesOfBooks(Database* db);
