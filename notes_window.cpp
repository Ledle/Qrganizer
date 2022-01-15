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
