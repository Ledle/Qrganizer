#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

private slots:
    void on_Tasks_lineEdit_editingFinished();

    void on_Calendar_lineEdit_editingFinished();

    void on_Notes_lineEdit_editingFinished();

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
