#ifndef TASKGROUP_H
#define TASKGROUP_H
#include "group.h"
#include <QListWidget>

class TaskGroup:public Group
{
private:
    static list<TaskGroup*>* groups;
public:
    TaskGroup();
    TaskGroup(QString name);
    static void Save();
    static void Load();
    static list<TaskGroup*> Groups();
    static void Show(QListWidget* list);
    static TaskGroup* getGroup(int n);
};

#endif // TASKGROUP_H
