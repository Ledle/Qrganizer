#ifndef GROUP_H
#define GROUP_H
#include <list>
#include <iostream>
#include <QListWidget>
#include <QList>

using namespace std;
class Event;
class Group
{
protected:
    QString name;
    QList<Event*>* events;
public:
    Group();
    Group(QString name);
    void Add(Event* e);
    void Remove(Event* e);
    QList<Event*>* Events();
    void ShowEvents(QListWidget* list);
    Event* getEvent(int n);
    QString getName();
    void setName(QString name);
};

#endif // GROUP_H
