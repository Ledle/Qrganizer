#include "group.h"
#include "event.h"
#include <QString>
#include <list>
Group::Group()
{
    name = "";
    events = new list<Event*>();
}
Group::Group(QString name) {
    this->name = name;
    events = new list<Event*>();
}
void Group::Add(Event* e) {
    bool contains = false;
    for (Event* evnt : *(this->events)) {
        if (e == evnt) {
            contains = true;
        }
    }
    if (!contains)
    {
        events->push_back(e);
        e->setGroup(this);
    }
}
void Group::Remove(Event* e) {
    for (auto i = events->begin(); i != events->end(); i++) {
        if (*i == e) {
            events->erase(i);
            break;
        }
    }
}
list<Event*>* Group::Events(){
    return events;
}
void Group::ShowEvents(QListWidget* list){
    list->clear();
    int n = 0;
    std::list<Event*>* evs = events;
    evs->empty();
    if (!(events->empty())){
    for (Event* e : *events){
        list->addItem(e->getName());
        list->item(n++)->setData(1,n);
    }
    }
}
Event* Group::getEvent(int n){
    for (Event* e : *events){
        if (n<=0){return e;}
        n--;
    }
}
