#include "eventgroup.h"
#include "event.h"

list<EventGroup*>* EventGroup::groups = new list<EventGroup*>();

EventGroup::EventGroup():Group()
{
	groups->push_back(this);
}
EventGroup::EventGroup(string name):Group(name){
	groups->push_back(this);
}
list<EventGroup*> EventGroup::Groups(){
	return *groups;
}
list<Event*> EventGroup::getEvents(QDate date){
    list<Event*> res = list<Event*>();
    for (Event* e : *(this->events)) {
        if (e->getDate().year() == date.year() && e->getDate().month() == date.month() && e->getDate().day() == date.day()){
            res.push_back(e);
        }
    }
    return res;
}
void EventGroup::Save(){}
void EventGroup::Load(){}
