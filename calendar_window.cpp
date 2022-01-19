#include "calendar_window.h"
#include "ui_calendar_window.h"
#include "event.h"
#include <QCloseEvent>
calendar_window::calendar_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::calendar_window)
{
    ui->setupUi(this);
    EventGroup::Load();
    setSelectedEvent(NULL);
    setSelectedGroup(NULL);
    ui->calendarWidget->setSelectedDate(QDate::currentDate());
    EventGroup::Show(ui->Groups_comboBox);
}

calendar_window::~calendar_window()
{
    delete ui;
}


void calendar_window::setSelectedEvent(Event* evnt) {
    if (evnt == NULL) {
        selectedEvent = NULL;

        ui->EventName_lineEdit->setDisabled(true);
        ui->Description_textEdit->setDisabled(true);


        ui->Delete_Button->setDisabled(true);
        ui->Date_Button->setDisabled(true);
        ui->Date_dateTimeEdit->hide();
    }
    else {
        selectedEvent = evnt;

        ui->EventName_lineEdit->setText(evnt->getName());
        ui->Description_textEdit->setDisabled(false);
        ui->Description_textEdit->setPlainText(evnt->getDescription());
        ui->EventName_lineEdit->setDisabled(false);
        if (selectedGroup != NULL) {
            ui->Delete_Button->setDisabled(false);
        }
        ui->Date_Button->setDisabled(false);
        if (selectedEvent->getDate().isNull()) {
            ui->Date_dateTimeEdit->hide();
        }
        else {
            ui->Date_dateTimeEdit->setDateTime(selectedEvent->getDate());
            ui->Date_dateTimeEdit->show();
        }
    }
}
void calendar_window::setSelectedGroup(EventGroup* group) {
    if (group == NULL) {
        selectedGroup = NULL;

        ui->Events_listWidget->setDisabled(true);
        ui->Events_listWidget->blockSignals(true);
        ui->Events_listWidget->clear();
        ui->Events_listWidget->blockSignals(true);

        ui->Groups_comboBox->setDisabled(true);
        ui->AddEvent_Button->setDisabled(true);
        ui->DeleteGroup_Button->setDisabled(true);
        ui->Delete_Button->setDisabled(true);
    }
    else {
        selectedGroup = group;

        ui->Events_listWidget->setDisabled(false);
        ui->Groups_comboBox->setDisabled(false);
        ui->Groups_comboBox->setCurrentIndex(EventGroup::Groups().indexOf(group));
        ui->AddEvent_Button->setDisabled(false);
        ui->DeleteGroup_Button->setDisabled(false);
        if (selectedEvent != NULL) {
            ui->Delete_Button->setDisabled(false);
        }
        if (!(group->Events()->isEmpty())) {
            setSelectedEvent(group->Events()->first());
        }
        else {
            ui->EventName_lineEdit->setText("");
            ui->EventName_lineEdit->setDisabled(true);
            ui->Description_textEdit->blockSignals(true);
            ui->Description_textEdit->setPlainText("");
            ui->Description_textEdit->blockSignals(false);
            ui->Description_textEdit->setDisabled(true);
        }
        selectedGroup->ShowEvents(ui->Events_listWidget, selectedGroup->getEvents(ui->calendarWidget->selectedDate()));
    }
}

void calendar_window::on_calendarWidget_clicked(const QDate& date)
{
    if (selectedGroup != NULL) {
        event_show(selectedGroup->getEvents(date));
        setSelectedEvent(NULL);
    }
}

void calendar_window::event_show(QList<Event*> evs) {
    ui->Events_listWidget->clear();
    for (Event* e : evs) {
        ui->Events_listWidget->addItem(e->getName());
    }

    ui->EventName_lineEdit->setText("");
    ui->Description_textEdit->blockSignals(true);
    ui->Description_textEdit->setPlainText("");
    ui->Description_textEdit->blockSignals(false);
}

void calendar_window::on_AddGroup_Button_clicked()
{
    if (ui->GroupName_lineEdit->text() != "") {
        EventGroup* grp = new EventGroup(ui->GroupName_lineEdit->text());
        EventGroup::Show(ui->Groups_comboBox);
        setSelectedGroup(grp);
        ui->GroupName_lineEdit->setText("");
    }
}


void calendar_window::on_AddEvent_Button_clicked()
{
    if (selectedGroup != NULL) {
        Event* evnt = new Event(ui->GroupEvent_lineEdit->text());
        selectedGroup->Add(evnt);
        evnt->setDate(QDateTime(ui->calendarWidget->selectedDate(), QTime()));
        QList<Event*> evs = selectedGroup->getEvents(ui->calendarWidget->selectedDate());
        selectedGroup->ShowEvents(ui->Events_listWidget,evs);
        setSelectedEvent(evnt);
        ui->GroupEvent_lineEdit->clear();
    }
}


void calendar_window::on_EventName_lineEdit_textEdited(const QString &arg1)
{
    selectedEvent->setName(arg1);
    QList<Event*> evs = selectedGroup->getEvents(ui->calendarWidget->selectedDate());
    selectedGroup->ShowEvents(ui->Events_listWidget,evs);
}


void calendar_window::on_Groups_comboBox_currentIndexChanged(int index)
{
    EventGroup* grp = EventGroup::Groups().at(index);
    //if (grp == selectedGroup) {
        //if (selectedEvent != NULL) {
            //selectedEvent->setGroup(grp);
            //selectedGroup->Remove(selectedEvent);
        //}
        ui->Groups_comboBox->blockSignals(true);
        setSelectedGroup(grp);
        ui->Groups_comboBox->blockSignals(false);
    //}
}


void calendar_window::on_DeleteGroup_Button_clicked()
{
    ui->Groups_comboBox->blockSignals(true);
    ui->Groups_comboBox->removeItem(EventGroup::Groups().indexOf(selectedGroup));
    ui->Groups_comboBox->blockSignals(false);
    EventGroup::RemoveGroup(selectedGroup);
    if (ui->Groups_comboBox->count() > 0) {
        setSelectedGroup(EventGroup::Groups().at(ui->Groups_comboBox->count()-1));
    }
    else {
        setSelectedGroup(NULL);
    }
    EventGroup::Show(ui->Groups_comboBox);
}


void calendar_window::on_Date_Button_clicked()
{
    if (ui->Date_dateTimeEdit->isVisible()) {
        ui->Date_dateTimeEdit->hide();
        selectedEvent->setDate(QDateTime());
    }
    else {
        ui->Date_dateTimeEdit->show();
        ui->Date_dateTimeEdit->setDate(QDate::currentDate());
    }
}


void calendar_window::on_Date_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    selectedEvent->setDate(dateTime);
}


void calendar_window::on_Delete_Button_clicked()
{
    selectedGroup->Remove(selectedEvent);
    setSelectedGroup(selectedGroup);
    setSelectedEvent(NULL);
    ui->EventName_lineEdit->setText("");
}

void calendar_window::on_Description_textEdit_textChanged()
{
    if (ui->Description_textEdit->toPlainText() != selectedEvent->getDescription()) {
        selectedEvent->setDescription(ui->Description_textEdit->toPlainText());
        QList<Event*> evs = selectedGroup->getEvents(ui->calendarWidget->selectedDate());
        selectedGroup->ShowEvents(ui->Events_listWidget,evs);
    }
}

void calendar_window::on_Save_Button_clicked()
{
    EventGroup::Save();
}


void calendar_window::on_Events_listWidget_itemSelectionChanged()
{

    int n = ui->Events_listWidget->currentRow();
    Event* evnt = selectedGroup->getEvent(n);
    if (evnt != selectedEvent) {
        setSelectedEvent(evnt);
    }
}
void calendar_window::closeEvent(QCloseEvent* event)
{
    if (this->isVisible()) {
        event->ignore();
        this->hide();
    }
}
