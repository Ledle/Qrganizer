#include "event.h"
#include "eventgroup.h"
#include <QDate>
Event::Event()
{
    name = "";
    description = "";
}
Event::Event(QString name){
    this->name = name;
    description = "";
}
QString Event::getName(){
    return name;
}
void Event::setName(QString name){
    this->name = name;
}
QString Event::getDescription(){
    return description;
}
void Event::setDescription(QString description){
    this->description = description;
}
Group* Event::getGroup(){
    return group;
}
void Event::setGroup(Group* group) {
    if (this->group != group)
    {
        bool contains = false;
        if (this->group != NULL) {
            for (Event* e : *(this->group->Events())) {
                if (e == this) {
                    contains = true;
                }
            }
            if (this->group != NULL && contains) { group->Remove(this); }
        }
        this->group = group;
    }
}
QDate Event::getDate(){
    return date;
}
void Event::setDate(QDate date){
    this->date = date;
}
QDateTime Event::getRemind() {
    return remind;
}
void Event::setRemind(QDateTime date) {
    remind = date;
}
Cycle Event::getCycle() {
    return cycle;
}
void Event::setCycle(Cycle date) {
    cycle = date;
}