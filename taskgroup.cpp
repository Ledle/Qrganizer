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
    for (int i = 0; i < n; i++) {
        stream >> g;
        groups->append(new TaskGroup(g));
    }
    file.close();
}
QList<TaskGroup*> TaskGroup::Groups() {
	return *groups;
}
void TaskGroup::Show(QListWidget* list){
    list->clear();
    int n = 0;
    for (TaskGroup* g : *groups){
        list->addItem(g->name);
        list->item(n++)->setData(1,n);
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
        evnt = new Task(t);
        evnt->setGroup(&g);
        g.events->push_back(new Task(t));
    }
    d >> g.name;
    return d;
}
