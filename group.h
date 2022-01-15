#ifndef GROUP_H
#define GROUP_H
#include <list>
#include <iostream>
#include <QListWidget>

using namespace std;
class Event;
class Group
{
protected:
    string name;
    list<Event*>* events;
public:
    Group();
    Group(string name);
    void Add(Event* e);
    void Remove(Event* e);
    list<Event*>* Events();
    void ShowEvents(QListWidget* list);
    Event* getEvent(int n);
};

#endif // GROUP_H
