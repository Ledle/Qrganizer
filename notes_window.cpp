#include "notes_window.h"
#include "ui_notes_window.h"

notes_window::notes_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::notes_window)
{
    ui->setupUi(this);
}

notes_window::~notes_window()
{
    delete ui;
}

void notes_window::on_AddGroup_Button_clicked()
{

}


void notes_window::on_Groups_listWidget_currentRowChanged(int currentRow)
{

}


void notes_window::on_Notes_listWidget_currentRowChanged(int currentRow)
{

}


void notes_window::on_Note_textEdit_textChanged()
{

}


void notes_window::on_Delete_Button_clicked()
{

}


void notes_window::on_Save_Button_clicked()
{

}


void notes_window::on_AddNote_Button_clicked()
{

}

