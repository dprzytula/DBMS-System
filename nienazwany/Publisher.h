#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "ROT13.h"

using namespace std;

struct Publisher {
	int idPublisher;
	string name;
};

void savePublisherToFile(int idPublisher, string name, bool append);
Publisher addPublisher();
Publisher addPublisher(int idPublisher, string name);
void displayPublisher(Publisher publisher);
