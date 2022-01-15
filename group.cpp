#include "group.h"
#include "event.h"
#include <QString>
#include <list>
Group::Group()
{
    name = "";
    events = new QList<Event*>();
}
Group::Group(QString name) {
    this->name = name;
    events = new QList<Event*>();
}
void Group::Add(Event* e) {
    if (!(events->contains(e)))
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
QList<Event*>* Group::Events(){
    return events;
}
void Group::ShowEvents(QListWidget* list){
    list->clear();
    int n = 0;
    QList<Event*>* evs = events;
    if (!(events->empty())){
    for (Event* e : *events){
        list->addItem(e->getName());
        list->item(n++)->setData(1,n);
    }
    }
}
Event* Group::getEvent(int n){
    return events->at(n);
}
