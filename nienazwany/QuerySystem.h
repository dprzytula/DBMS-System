#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <QVector>
#include <QMap>
#include <QDebug>
#include "Database.h"

using namespace std;

class QuerySystem {
public:
    void executeQuery(string query, Database *db, list<QMap<QString, QString>> *results);

    void doSelect(string query, int operationID, Database* db, list<QMap<QString, QString>> *results);
	bool doUpdate(string query, int operationID, Database* db);
	bool doDelete(string query, int operationID, Database* db);
	bool doInsert(string query, int operationID, Database* db);
	void clearFile(string file);
};
