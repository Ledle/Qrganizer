#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <list>
#include <QDate>
#include <QDAteTime>
#include <QString>

using namespace std;
enum Cycle {
    DAY,
    WEEK,
    MONTH,
    YEAR,
    EMPTY,
};
class Group;
class Event
{
protected:
    Group* group = NULL;
    QString name;
    QString description;
    QDate date;
    QDateTime remind;
    Cycle cycle = Cycle::EMPTY;
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
    QDateTime getRemind();
    void setRemind(QDateTime date);
    Cycle getCycle();
    void setCycle(Cycle date);
};

#endif // EVENT_H
