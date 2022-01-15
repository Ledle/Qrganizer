#include "task.h"
Task::Task():Event()
{
	complete = false;
}
Task::Task(QString name):Event(name) {
	complete = false;
}
bool Task::Completed() {
	return complete;
}
void Task::Complete() {
	complete = true;
}
void Task::Uncomplete() {
	complete = false;
}