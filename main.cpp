#include "tasks_window.h"
#include "notes_window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Tasks_Window w;
    notes_window w;
    w.show();
    return a.exec();
}
