#include "calendar_window.h"
#include "ui_calendar_window.h"

calendar_window::calendar_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::calendar_window)
{
    ui->setupUi(this);
}

calendar_window::~calendar_window()
{
    delete ui;
}

void calendar_window::on_calendarWidget_selectionChanged()
{

}


void calendar_window::on_AddGroup_Button_clicked()
{

}


void calendar_window::on_AddEvent_Button_clicked()
{

}


void calendar_window::on_EventName_lineEdit_textEdited(const QString &arg1)
{

}


void calendar_window::on_Groups_comboBox_currentIndexChanged(int index)
{

}


void calendar_window::on_DeleteGroup_Button_clicked()
{

}


void calendar_window::on_Date_Button_clicked()
{

}


void calendar_window::on_Date_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{

}


void calendar_window::on_Remind_Button_clicked()
{

}


void calendar_window::on_Remind_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{

}


void calendar_window::on_Cycle_Button_clicked()
{

}


void calendar_window::on_Cycle_comboBox_currentIndexChanged(int index)
{

}


void calendar_window::on_Delete_Button_clicked()
{

}


void calendar_window::on_Save_Button_clicked()
{

}


void calendar_window::on_Events_listWidget_itemSelectionChanged()
{

}
