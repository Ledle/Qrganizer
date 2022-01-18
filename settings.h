#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QString>
#include <QFile>
#include <QLineEdit>
#include <QLabel>
#include <QSystemTrayIcon>
#include <QMainWindow>

#include "tasks_window.h"
#include "notes_window.h"
#include "calendar_window.h"

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();
    static QString Task;
    static QString Calendar;
    static QString Note;

private slots:
    void on_Tasks_lineEdit_editingFinished();

    void on_Calendar_lineEdit_editingFinished();

    void on_Notes_lineEdit_editingFinished();

    void iconActivated(QSystemTrayIcon::ActivationReason reason);

    void OpenTask();

    void OpenCalendar();

    void OpenNote();
protected:
    void closeEvent(QCloseEvent* event);
private:
    Ui::Settings *ui;
    bool error=false;
    bool Load();
    bool Save();
    bool fileexist(QLineEdit*, QLabel*);
    QSystemTrayIcon* trayIcon;
    Tasks_Window* wt = new Tasks_Window();
    calendar_window* wc = new calendar_window();
    notes_window* wn = new notes_window();
};

#endif // SETTINGS_H
