#ifndef EVENTGROUP_H
#define EVENTGROUP_H
#include "group.h"
#include <QDate>

class EventGroup:public Group
{
private:
    static list<EventGroup*>* groups;
public:
    EventGroup();
    EventGroup(QString name);
    static list<EventGroup*> Groups();
    static void Save();
    static void Load();
    list<Event*> getEvents(QDate date);
};

#endif // EVENTGROUP_H
