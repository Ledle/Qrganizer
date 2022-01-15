#include "eventgroup.h"
#include "event.h"

QList<EventGroup*>* EventGroup::groups = new QList<EventGroup*>();

EventGroup::EventGroup():Group()
{
	groups->push_back(this);
}
EventGroup::EventGroup(QString name):Group(name){
	groups->push_back(this);
}
QList<EventGroup*> EventGroup::Groups(){
	return *groups;
}
QList<Event*> EventGroup::getEvents(QDate date){
    QList<Event*> res = QList<Event*>();
    for (Event* e : *(this->events)) {
        if (e->getDate().year() == date.year() && e->getDate().month() == date.month() && e->getDate().day() == date.day()){
            res.push_back(e);
        }
    }
    return res;
}
void EventGroup::Save(){}
void EventGroup::Load(){}
