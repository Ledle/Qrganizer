#include "taskgroup.h"

QList<TaskGroup*>* TaskGroup::groups = new QList<TaskGroup*>();
TaskGroup::TaskGroup():Group()
{
	groups->push_back(this);
}
TaskGroup::TaskGroup(QString name):Group(name) {
	groups->push_back(this);
}
void TaskGroup::Save() {
}
void TaskGroup::Load() {
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
