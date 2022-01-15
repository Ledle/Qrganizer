#include "tasks_window.h"
#include "ui_tasks_window.h"
#include "taskgroup.h"
Tasks_Window::Tasks_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Tasks_Window)
{
    ui->setupUi(this);
}

Tasks_Window::~Tasks_Window()
{
    delete ui;
}

void Tasks_Window::on_AddGroup_Button_clicked()
{
    if (ui->GroupName_lineEdit->text() != ""){
        new TaskGroup(ui->GroupName_lineEdit->text().toStdString());
    }
    TaskGroup::Show(ui->Groups_listWidget);
}

void Tasks_Window::on_Groups_listWidget_itemClicked(QListWidgetItem *item)
{
    int n = item->data(1).toInt();
    TaskGroup* grp = TaskGroup::getGroup(n-1);
    grp->ShowEvents(ui->Tasks_listWidget);
}

void Tasks_Window::on_AddTask_Button_clicked()
{

}


void Tasks_Window::on_Delete1_Button_clicked()
{

}


void Tasks_Window::on_Cycle1_Button_clicked()
{

}


void Tasks_Window::on_Remind1_Button_clicked()
{

}


void Tasks_Window::on_CompleteDate1_Button_clicked()
{

}


void Tasks_Window::on_Delete_Button_clicked()
{

}


void Tasks_Window::on_TaskName_lineEdit_textChanged(const QString &arg1)
{

}


void Tasks_Window::on_TaskNotes_textEdit_textChanged()
{

}


void Tasks_Window::on_Tasks_listWidget_itemClicked(QListWidgetItem *item)
{

}

