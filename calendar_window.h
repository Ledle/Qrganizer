#ifndef CALENDAR_WINDOW_H
#define CALENDAR_WINDOW_H

#include <QWidget>

namespace Ui {
class calendar_window;
}

class calendar_window : public QWidget
{
    Q_OBJECT

public:
    explicit calendar_window(QWidget *parent = nullptr);
    ~calendar_window();

private slots:
    void on_calendarWidget_selectionChanged();

    void on_AddGroup_Button_clicked();

    void on_AddEvent_Button_clicked();

    void on_EventName_lineEdit_textEdited(const QString &arg1);

    void on_Events_listWidget_itemClicked(QListWidgetItem *item);

    void on_Groups_comboBox_currentIndexChanged(int index);

    void on_DeleteGroup_Button_clicked();

    void on_Date_Button_clicked();

    void on_Date_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime);

    void on_Remind_Button_clicked();

    void on_Remind_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime);

    void on_Cycle_Button_clicked();

    void on_Cycle_comboBox_currentIndexChanged(int index);

    void on_Delete_Button_clicked();

    void on_Save_Button_clicked();

    void on_Events_listWidget_itemSelectionChanged();

private:
    Ui::calendar_window *ui;
};

#endif // CALENDAR_WINDOW_H
