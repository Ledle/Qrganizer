#include "settings.h"
#include "ui_settings.h"

#include <QFile>
#include <QStyle>
#include <QCloseEvent>
#include <QMenu>

#define CONFIG_FILE "Settings.cfg"

QString Settings::Task = "";
QString Settings::Calendar = "";
QString Settings::Note = "";
Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);


    this->setWindowTitle("Tray Program");
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));
    trayIcon->setToolTip("Tray Program");

    QMenu* menu = new QMenu(this);
    QAction* viewWindow = new QAction("Settings", this);
    QAction* quitAction = new QAction("Exit", this);
    QAction* openTask = new QAction("Task", this);
    QAction* openCalendar = new QAction("Calendar", this);
    QAction* openNote = new QAction("Note", this);

    connect(viewWindow, SIGNAL(triggered()), this, SLOT(show()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));
    connect(openTask, SIGNAL(triggered()), this, SLOT(OpenTask()));
    connect(openCalendar, SIGNAL(triggered()), this, SLOT(OpenCalendar()));
    connect(openNote, SIGNAL(triggered()), this, SLOT(OpenNote()));

    menu->addAction(viewWindow);
    menu->addAction(openTask);
    menu->addAction(openCalendar);
    menu->addAction(openNote);
    menu->addAction(quitAction);

    trayIcon->setContextMenu(menu);
    trayIcon->show();

    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
        this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));



    ui->label_2->hide();
    ui->Error_label->hide();
    if (!Load()) {
        Task = "Task";
        Calendar = "Calendar";
        Note = "Note";
        if (!Save()) {
            error = true;
        }
    }
    if (error) {
        ui->Calendar_label->hide();
        ui->Calendar_lineEdit->hide();
        ui->Tasks_label->hide();
        ui->Tasks_lineEdit->hide();
        ui->Notes_label->hide();
        ui->Notes_lineEdit->hide();
        ui->Error_label->show();
    }
    else {
        ui->Calendar_lineEdit->setText(Calendar);
        ui->Tasks_lineEdit->setText(Task);
        ui->Notes_lineEdit->setText(Note);
    }
}

Settings::~Settings()
{
    delete ui;
}

bool Settings::Load() {
    QFile cfg = QFile(CONFIG_FILE);
    bool f = cfg.open(QIODevice::ReadOnly);
    if (f) {
        QTextStream in(&cfg);
        in >> Task;
        in >> Calendar;
        in >> Note;
        ui->Calendar_lineEdit->setText(Calendar);
        ui->Tasks_lineEdit->setText(Task);
        ui->Notes_lineEdit->setText(Note);
        cfg.close();
    }
    return f;
}
bool Settings::Save() {
    QFile cfg = QFile(CONFIG_FILE);
    bool f = cfg.open(QIODevice::WriteOnly);
    if (f) {
        QTextStream out(&cfg);
        out << Task << '\n';
        out << Calendar << '\n';
        out << Note << '\n';
        cfg.close();
    }
    return f;
}

bool Settings::fileexist(QLineEdit* line, QLabel* label) {
    if (line->text().isEmpty()) { return false; }
    QFile f = QFile(line->text());
    if (f.open(QIODevice::ReadOnly)) {
        f.close();
        return true;
    }
    else {
        if (f.open(QIODevice::WriteOnly)) {
            f.close();
        }
        else {
            return false;
        }
    }
}

void Settings::on_Tasks_lineEdit_editingFinished()
{
    if (!fileexist(ui->Tasks_lineEdit, ui->label_2)) {
        ui->Tasks_lineEdit->setText(Task);
    }
    else {
        Task = ui->Tasks_lineEdit->text();
    }
}


void Settings::on_Calendar_lineEdit_editingFinished()
{
    if (!fileexist(ui->Calendar_lineEdit, ui->label_2)) {
        ui->Calendar_lineEdit->setText(Calendar);
    }
    else {
        Calendar = ui->Calendar_lineEdit->text();
    }
}


void Settings::on_Notes_lineEdit_editingFinished()
{
    if (!fileexist(ui->Notes_lineEdit, ui->label_2)) {
        ui->Notes_lineEdit->setText(Note);
    }
    else {
        Note = ui->Notes_lineEdit->text();
    }
}

void Settings::closeEvent(QCloseEvent* event)
{
    if (this->isVisible() && !error) {
        event->ignore();
        this->hide();
    }
}

void Settings::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        if (!error) {
            if (!this->isVisible()) {
                this->show();
            }
            else {
                this->hide();
            }
        }
        break;
    default:
        break;
    }
}

void Settings::OpenTask() {
    wt->show();
}

void Settings::OpenCalendar() {
    wc->show();
}

void Settings::OpenNote() {
    wn->show();
}