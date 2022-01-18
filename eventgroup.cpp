#include "eventgroup.h"
#include "event.h"
#include <QFile>
#include <QDataStream>
#include "settings.h"

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
        if (e->getDate().date().year() == date.year() && e->getDate().date().month() == date.month() && e->getDate().date().day() == date.day()) {
            res.push_back(e);
        }
    }
    return res;
}
void EventGroup::RemoveGroup(EventGroup* group) {
    groups->removeAt(groups->indexOf(group));
}
void EventGroup::Show(QComboBox* box) {
    box->blockSignals(true);
    box->clear();
    box->blockSignals(false);
    for (EventGroup* g : *groups) {
        box->addItem(g->name);
    }
}
void EventGroup::Save(){
    QFile file(Settings::Calendar);
    QDataStream stream(&file);
    file.open(QIODevice::WriteOnly);
    int n = groups->size();
    stream << n;
    for (int i = 0; i < groups->size(); i++) {
        stream << *(groups->at(i));
    }
    file.close();
}
void EventGroup::Load(){
    QFile file(Settings::Calendar);
    QDataStream stream(&file);
    file.open(QIODevice::ReadOnly);
    int n;
    stream >> n;
    EventGroup* grp;
    Event* tsk;
    for (int i = 0; i < n; i++) {
        grp = new EventGroup();
        stream >> *grp;
        for (Event* t : *(grp->events)) {
            tsk = t;
            tsk->setGroup(grp);
        }
    }
    file.close();
}

QDataStream& operator<<(QDataStream& d, const EventGroup& g) {
    int n = g.events->size();
    d << n;
    Event* t;
    for (int i = 0; i < g.events->size(); i++) {
        t = g.events->at(i);
        d << *t;
    }
    d << g.name;
    return d;
}
QDataStream& operator>>(QDataStream& d, EventGroup& g) {
    int n;
    d >> n;
    Event t;
    Event* evnt;
    for (int i = 0; i < n; i++) {
        d >> t;
        g.events->push_back(new Event(t));
    }
    d >> g.name;
    return d;
}

void EventGroup::ShowEvents(QListWidget* list, QList<Event*> evs) {
    list->blockSignals(true);
    list->clear();
    list->blockSignals(false);
    int n = 0;
    if (!(evs.empty())) {
        for (Event* e : evs) {
            list->addItem(e->getName());
            list->item(n++)->setData(1, n);
        }
    }
}