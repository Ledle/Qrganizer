#ifndef TASKGROUP_H
#define TASKGROUP_H
#include "group.h"
#include <QListWidget>
#include <QComboBox>

class TaskGroup:public Group
{
private:
    static QList<TaskGroup*>* groups;
public:
    TaskGroup();
    TaskGroup(QString name);
    static void Save();
    static void Load();
    static QList<TaskGroup*> Groups();
    static void Show(QListWidget* list, QComboBox* box);
    static TaskGroup* getGroup(int n);
    void ShowEvents(QListWidget* list);
    friend QDataStream& operator>>(QDataStream& d, TaskGroup& g);
    friend QDataStream& operator<<(QDataStream& d, const TaskGroup& g);
};
#endif // TASKGROUP_H