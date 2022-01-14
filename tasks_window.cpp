#include "tasks_window.h"
#include "ui_tasks_window.h"

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

