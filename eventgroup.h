#ifndef EVENTGROUP_H
#define EVENTGROUP_H
#include "group.h"
#include <QDate>
#include <QCombobox>

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
    static void RemoveGroup(EventGroup* group);
    static void Show(QComboBox* box);
    void ShowEvents(QListWidget* list,QList<Event*> evs);
    friend QDataStream& operator>>(QDataStream& d, EventGroup& g);
    friend QDataStream& operator<<(QDataStream& d, const EventGroup& g);
};

#endif // EVENTGROUP_H
