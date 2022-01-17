#include "tasks_window.h"
#include "ui_tasks_window.h"
#include "taskgroup.h"
#include "task.h"

Tasks_Window::Tasks_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Tasks_Window)
{
    ui->setupUi(this);
    TaskGroup::Load();
    TaskGroup::Show(ui->Groups_listWidget,ui->Groups_comboBox);
    ui->Task_groupBox->hide();
    ui->Add_groupBox->hide();
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
    selectedTask = NULL;
    ui->Task_groupBox->hide();
    TaskGroup::Show(ui->Groups_listWidget, ui->Groups_comboBox);
}

void Tasks_Window::on_Groups_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->Task_groupBox->hide();
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
    ui->Task_groupBox->show();
}


void Tasks_Window::on_AddTask_Button_clicked()
{
    if (ui->NameTask_lineEdit->text() != "") {
        Task* t = new Task(ui->NameTask_lineEdit->text());
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
    //TaskGroup::Save();
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
    int i = TaskGroup::Groups().indexOf(selectedGroup);
    ui->Groups_comboBox->setCurrentIndex(i);
    if (!(tsk->getDate().isNull())) {
        ui->Complete_dateEdit->setDate(QDate(tsk->getDate().date()));
        ui->Complete_dateEdit->show();
    }
    else {
        ui->Complete_dateEdit->hide();
    }
    if (!(tsk->getRemind().isNull())) {
        ui->Remind_dateTimeEdit->setDateTime(tsk->getRemind());
        ui->Remind_dateTimeEdit->show();
    }
    else {
        ui->Remind_dateTimeEdit->hide();
    }
    if (tsk->getCycle() == Cycle::EMPTY) {
        ui->Cycle_comboBox->hide();
    }
    else {
        ui->Cycle_comboBox->setCurrentIndex(tsk->getCycle());
        ui->Cycle_comboBox->show();
    }
}

void Tasks_Window::on_Groups_comboBox_currentIndexChanged(int index)
{
    TaskGroup* grp = TaskGroup::Groups().at(index);
    if (grp != selectedGroup && selectedTask != NULL) {
        selectedTask->setGroup(grp);
        selectedGroup->Remove(selectedTask);
        grp->Add(selectedTask);
        selectedGroup = grp;
        ui->Groups_listWidget->setCurrentRow(index);
        grp->ShowEvents(ui->Tasks_listWidget);
        task_show(selectedTask);
    }
}


void Tasks_Window::on_Cycle_Button_clicked()
{
    Cycle c;
    if (ui->Cycle_comboBox->isVisible()) {
        ui->Cycle_comboBox->hide();
        selectedTask->setCycle(Cycle::EMPTY);
    }
    else {
        ui->Cycle_comboBox->show();
        c = static_cast<Cycle>(ui->Cycle_comboBox->currentIndex());
        selectedTask->setCycle(c);
    }
}


void Tasks_Window::on_Complete_Box_stateChanged(int arg1)
{
    if (arg1 == 0) {
        selectedTask->Uncomplete();
    }
    else {
        selectedTask->Complete();
    }
}


void Tasks_Window::on_Remind_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    selectedTask->setRemind(dateTime);
}


void Tasks_Window::on_Complete_dateEdit_dateChanged(const QDate &date)
{
    selectedTask->setDate(QDateTime(date,QTime()));
}


void Tasks_Window::on_Remind_Button_clicked()
{
    if (ui->Remind_dateTimeEdit->isVisible()) {
        ui->Remind_dateTimeEdit->hide();
        selectedTask->setRemind(QDateTime());
    }
    else {
        ui->Remind_dateTimeEdit->show();
        QDateTime remind = selectedTask->getDate();
        selectedTask->setRemind(remind);
        ui->Remind_dateTimeEdit->setDateTime(remind);
    }
}

void Tasks_Window::on_CompleteDate_Button_clicked()
{
    if (ui->Complete_dateEdit->isVisible()) {
        ui->Complete_dateEdit->hide();
        selectedTask->setDate(QDateTime());
    }
    else {
        ui->Complete_dateEdit->show();
        ui->Complete_dateEdit->setDate(QDate::currentDate());
    }
}