#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <list>
#include <QDate>
#include <QString>

using namespace std;
class Group;
class Event
{
protected:
    Group* group = NULL;
    QString name;
    QString description;
    QDate date;
public:
    Event();
    Event(QString name);
    QString getName();
    void setName(QString name);
    QString getDescription();
    void setDescription(QString description);
    Group* getGroup();
    void setGroup(Group* group);
    void setDate(QDate date);
    QDate getDate();
};

#endif // EVENT_H
