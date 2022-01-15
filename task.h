#ifndef TASK_H
#define TASK_H
#include "event.h"

using namespace std;

class Task:public Event
{
private:
    bool complete;
public:
    Task();
    Task(QString name);
    bool Completed();
    void Complete();
    void Uncomplete();
};

#endif // TASK_H
