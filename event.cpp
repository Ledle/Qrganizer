#include "event.h"
#include "eventgroup.h"
#include <QDate>
Event::Event()
{
    name = "";
    description = "";
}
Event::Event(string name){
    this->name = name;
    description = "";
}
string Event::getName(){
    return name;
}
void Event::setName(string name){
    this->name = name;
}
string Event::getDescription(){
    return description;
}
void Event::setDescription(string description){
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
