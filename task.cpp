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
QDataStream& operator<<(QDataStream& d, const Task& u) {
	d << u.name << u.description << u.date << u.complete << u.cycle << u.remind;
	return d;
}
QDataStream& operator>>(QDataStream& d, Task& u) {
	d >> u.name >> u.description >> u.date >> u.complete >> u.cycle >> u.remind;
	return d;
}