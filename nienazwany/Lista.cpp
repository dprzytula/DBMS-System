#include "Lista.h"

void displayReader(TlistElement r) {
    cout << "ID: " << r.key << " | First Name: " << r.nazwaKs << endl;

}

unsigned TdoubleList::size()
{
    return counter;
}
TlistElement* TdoubleList::push_front(TlistElement* p)
{
    p->next = front; p->prev = NULL;
    if (front) front->prev = p;
    front = p;
    if (!back) back = front;
    counter++;
    return front;
}
TlistElement* TdoubleList::push_back(TlistElement* p)
{
    if (back) back->next = p;
    p->next = NULL; p->prev = back;
    back = p;
    if (!front) front = back;
    counter++;
    return back;
}

TlistElement* TdoubleList::insert(TlistElement* p1, TlistElement* p2)
{
    p1->next = p2->next; p1->prev = p2;
    p2->next = p1;
    if (p1->next) p1->next->prev = p1;
    else back = p1;
    counter++;
    return p1;
}

TlistElement* TdoubleList::pop_front()
{
    TlistElement* p;

    if (front)
    {
        p = front;
        front = front->next;
        if (!front) back = NULL;
        else front->prev = NULL;
        counter--;
        return p;
    }
    else return NULL;
}

TlistElement* TdoubleList::pop_back()
{
    TlistElement* p;

    if (back)
    {
        p = back;
        if (p == front) front = back = NULL;
        else
        {
            back = back->prev;
            back->next = NULL;
        };
        counter--;
        return p;
    }
    else return NULL;
}

TlistElement* TdoubleList::erase(TlistElement* p)
{


    if (p->prev) p->prev->next = p->next;
    else front = p->next;
    if (p->next) p->next->prev = p->prev;
    else back = p->prev;
    counter--;
    return p;
}

TlistElement* TdoubleList::index(unsigned n)
{
    TlistElement* p;

    if ((!n) || (n > counter)) return NULL;
    else if (n == counter) return back;
    else if (n < counter / 2)
    {
        p = front;
        while (--n) p = p->next;
        return p;
    }
    else
    {
        p = back;
        while (counter > n++) p = p->prev;
        return p;
    }
}
void TdoubleList::showList()
{
    TlistElement* p;
    if (!front) cout << "Lista jest pusta." << endl;
    else
    {
        p = front;
        while (p)
        {
            displayReader(*p);
            p = p->next;
        }
    }


}
/* void showKeys()
 {
     TlistElement* p;

     if (!front) cout << "Lista jest pusta." << endl;
     else
     {
         p = front;
         while (p)
         {
             cout << p->key << " "<< p->nazwaKs<<endl;
             p = p->next;
         }
         cout << endl;
     }
 }*/




 /*int main()
 {
     TdoubleList    dl;
     TlistElement* p;
     int            i;
     string dane = "siema";


     for (i = 0; i <10; i++) {
         p = new TlistElement;
         p->key = i;
         p->nazwaKs = dane;
         dl.push_front(p);
     }

     cout << "(A) : ";   dl.showList();


     dl.pop_back();

     cout << "(B) : ";   dl.showList();
     cout << endl << endl;
     system("PAUSE");
 }*/