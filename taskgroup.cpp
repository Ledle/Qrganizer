#include "taskgroup.h"

list<TaskGroup*>* TaskGroup::groups = new list<TaskGroup*>();
TaskGroup::TaskGroup():Group()
{
	groups->push_back(this);
}
TaskGroup::TaskGroup(string name):Group(name) {
	groups->push_back(this);
}
void TaskGroup::Save() {
}
void TaskGroup::Load() {
}
list<TaskGroup*> TaskGroup::Groups() {
	return *groups;
}
void TaskGroup::Show(QListWidget* list){
    list->clear();
    int n = 0;
    for (TaskGroup* g : *groups){
        list->addItem(QString::fromStdString(g->name));
        list->item(n++)->setData(1,n);
    }
}
TaskGroup* TaskGroup::getGroup(int n){
    for (TaskGroup* g : *groups){
        if (n<=0){return g;}
        n--;
    }
}
