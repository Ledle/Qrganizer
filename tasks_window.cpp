#include "tasks_window.h"
#include "ui_tasks_window.h"
#include "taskgroup.h"
#include "task.h"
Tasks_Window::Tasks_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Tasks_Window)
{
    ui->setupUi(this);
    //TaskGroup* grp = new TaskGroup("Hello");grp->Add(new Task("World"));
    TaskGroup::Load();
    TaskGroup::Show(ui->Groups_listWidget);
    ui->Task_groupBox->hide();
    ui->Add_groupBox->hide();
    //TaskGroup::Save();
}

Tasks_Window::~Tasks_Window()
{
    delete ui;
}

void Tasks_Window::on_AddGroup_Button_clicked()
{
    if (ui->GroupName_lineEdit->text() != ""){
        new TaskGroup(ui->GroupName_lineEdit->text());
    }
    TaskGroup::Show(ui->Groups_listWidget);
}

void Tasks_Window::on_Groups_listWidget_itemClicked(QListWidgetItem *item)
{
    int n = item->data(1).toInt();
    TaskGroup* grp = TaskGroup::getGroup(n-1);
    grp->ShowEvents(ui->Tasks_listWidget);
    selectedGroup = grp;
    ui->Add_groupBox->show();
}

void Tasks_Window::on_Tasks_listWidget_itemClicked(QListWidgetItem* item)
{
    int n = item->data(1).toInt();
    Task* tsk = (Task*)(selectedGroup->getEvent(n - 1));
    if (tsk != selectedTask) {
        task_show(tsk);
    }
    else {
        if (ui->Task_groupBox->isHidden()) {
            ui->Task_groupBox->show();
        }
        else {
            ui->Task_groupBox->hide();
        }
    }
}


void Tasks_Window::on_AddTask_Button_clicked()
{
    if (ui->NameTask_lineEdit->text() != "") {
        Task* t = new Task(ui->NameTask_lineEdit->text());//��������
        selectedGroup->Add(t);
        selectedGroup->ShowEvents(ui->Tasks_listWidget);
        ui->NameTask_lineEdit->clear();
    }
}


void Tasks_Window::on_Delete_Button_clicked()
{
    Group* grp = selectedTask->getGroup();
    grp->Remove(selectedTask);
    grp->ShowEvents(ui->Tasks_listWidget);
}


void Tasks_Window::on_TaskName_lineEdit_textChanged(const QString &arg1)
{
    if (ui->TaskName_lineEdit->text() != selectedTask->getName()) {
        selectedTask->setName(ui->TaskName_lineEdit->text());
        selectedGroup->ShowEvents(ui->Tasks_listWidget);
    }
}


void Tasks_Window::on_TaskNotes_textEdit_textChanged()
{
    if (ui->TaskNotes_textEdit->toPlainText() != selectedTask->getDescription()) {
        selectedTask->setDescription(ui->TaskNotes_textEdit->toPlainText());
        selectedGroup->ShowEvents(ui->Tasks_listWidget);
    }
}


void Tasks_Window::task_show(Task* tsk) {
    selectedTask = tsk;
    ui->TaskName_lineEdit->setText(tsk->getName());
    ui->TaskNotes_textEdit->setText(tsk->getDescription());
    ui->Complete_Box->setChecked(tsk->Completed());
}

void Tasks_Window::on_Groups_comboBox_currentIndexChanged(int index)
{

}


void Tasks_Window::on_Cycle_Button_clicked()
{

}


void Tasks_Window::on_Complete_Box_stateChanged(int arg1)
{

}


void Tasks_Window::on_comboBox_currentIndexChanged(int index)
{

}


void Tasks_Window::on_Remind_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{

}


void Tasks_Window::on_Complete_dateEdit_dateChanged(const QDate &date)
{

}


void Tasks_Window::on_Remind_Button_clicked()
{

}

void Tasks_Window::on_CompleteDate_Button_clicked()
{

}

