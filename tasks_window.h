#ifndef TASKS_WINDOW_H
#define TASKS_WINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Tasks_Window; }
QT_END_NAMESPACE

class Tasks_Window : public QMainWindow
{
    Q_OBJECT

public:
    Tasks_Window(QWidget *parent = nullptr);
    ~Tasks_Window();

private:
    Ui::Tasks_Window *ui;
};
#endif // TASKS_WINDOW_H
