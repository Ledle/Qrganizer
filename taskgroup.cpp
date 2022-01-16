#include "taskgroup.h"
#include "task.h"
#include <QFile>
#include <QDataStream>
QList<TaskGroup*>* TaskGroup::groups = new QList<TaskGroup*>();
TaskGroup::TaskGroup():Group()
{
	groups->push_back(this);
}
TaskGroup::TaskGroup(QString name):Group(name) {
	groups->push_back(this);
}
void TaskGroup::Save() {
    QFile file("Task");
    QDataStream stream(&file);
    file.open(QIODevice::WriteOnly);
    int n = groups->size();
    stream << n;
    for (int i = 0; i < groups->size(); i++) {
        stream << *(groups->at(i));
    }
    file.close();
}
void TaskGroup::Load() {
    QFile file("Task");
    QDataStream stream(&file);
    bool f = file.open(QIODevice::ReadOnly);
    int n;
    stream >> n;
    TaskGroup g;
    groups->pop_back();
    TaskGroup* grp;
    Task* tsk;
    for (int i = 0; i < n; i++) {
        g.events = new QList<Event*>();
        stream >> g;
        grp = new TaskGroup(g);
        for (Event* t : *(grp->events)) {
            tsk = (Task*)t;
            tsk->setGroup(grp);
        }
        groups->append(grp);
    }
    file.close();
}
QList<TaskGroup*> TaskGroup::Groups() {
	return *groups;
}
void TaskGroup::Show(QListWidget* list, QComboBox* box){
    list->clear();
    int n = 0;
    for (int i = 0; i < box->count();i++) {
        box->removeItem(i);
    }
    for (TaskGroup* g : *groups){
        list->addItem(g->name);
        list->item(n++)->setData(1,n);
        box->addItem(g->name);
    }
}
TaskGroup* TaskGroup::getGroup(int n){
    return groups->at(n);
}

QDataStream& operator<<(QDataStream& d, const TaskGroup& g) {
    int n = g.events->size();
    d << n;
    Task* t;
    for (int i = 0; i < g.events->size(); i++) {
        t = (Task*)(g.events->at(i));
        d << *t;
    }
    d << g.name;
    return d;
}
QDataStream& operator>>(QDataStream& d, TaskGroup& g) {
    int n;
    d >> n;
    Task t;
    Task* evnt;
    for (int i = 0; i < n; i++) {
        d >> t;
        g.events->push_back(new Task(t));
    }
    d >> g.name;
    return d;
}
