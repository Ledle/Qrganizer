#include "tasks_window.h"
#include "notes_window.h"
#include "calendar_window.h"
#include "settings.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Tasks_Window w;
    //notes_window w;
    //calendar_window w;
    Settings w;
    w.show();
    return a.exec();
}
