#ifndef EVENTGROUP_H
#define EVENTGROUP_H
#include "group.h"
#include <QDate>

class EventGroup:public Group
{
private:
    static QList<EventGroup*>* groups;
public:
    EventGroup();
    EventGroup(QString name);
    static QList<EventGroup*> Groups();
    static void Save();
    static void Load();
    QList<Event*> getEvents(QDate date);
};

#endif // EVENTGROUP_H
