#ifndef TASKS_WINDOW_H
#define TASKS_WINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "taskgroup.h"
#include "task.h"
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
    TaskGroup* selectedGroup = NULL;
    Task* selectedTask=NULL;
    void task_show(Task* tsk);
private slots:
    void on_AddGroup_Button_clicked();

    void on_Groups_listWidget_itemClicked(QListWidgetItem *item);

    void on_AddTask_Button_clicked();

    void on_Delete1_Button_clicked();

    void on_Cycle1_Button_clicked();

    void on_Remind1_Button_clicked();

    void on_CompleteDate1_Button_clicked();

    void on_Delete_Button_clicked();

    void on_TaskName_lineEdit_textChanged(const QString &arg1);

    void on_TaskNotes_textEdit_textChanged();

    void on_Tasks_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::Tasks_Window *ui;
};
#endif // TASKS_WINDOW_H
