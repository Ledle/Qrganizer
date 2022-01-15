#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <list>
#include <QDate>

using namespace std;
class Group;
class Event
{
protected:
    Group* group = NULL;
    string name;
    string description;
    QDate date;
public:
    Event();
    Event(string name);
    string getName();
    void setName(string name);
    string getDescription();
    void setDescription(string description);
    Group* getGroup();
    void setGroup(Group* group);
    void setDate(QDate date);
    QDate getDate();
};

#endif // EVENT_H
