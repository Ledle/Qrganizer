#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_Tasks_lineEdit_editingFinished()
{

}


void Settings::on_Calendar_lineEdit_editingFinished()
{

}


void Settings::on_Notes_lineEdit_editingFinished()
{

}

