#pragma once
#include <iostream>
#include <string>
using namespace std;

struct TlistElement
{
    TlistElement* next, * prev;
    int key;
    string nazwaKs;
};
void displayReader(TlistElement r);

class TdoubleList
{
private:
    TlistElement* front, * back;
    unsigned counter;
public:
    TdoubleList()
    {
        front = back = NULL;
        counter = 0;
    }
    ~TdoubleList()
    {
        TlistElement* p;

        while (front)
        {
            p = front->next;
            delete front;
            front = p;
        }
    }
    unsigned size();
    TlistElement* push_front(TlistElement* p);
    TlistElement* push_back(TlistElement* p);
    TlistElement* insert(TlistElement* p1, TlistElement* p2);
    TlistElement* pop_front();
    TlistElement* pop_back();
    TlistElement* erase(TlistElement* p);
    TlistElement* index(unsigned n);
    void showList();

};