#ifndef NOTES_WINDOW_H
#define NOTES_WINDOW_H

#include <QWidget>

#include "notegroup.h"
#include "note.h"

namespace Ui {
class notes_window;
}

class notes_window : public QWidget
{
    Q_OBJECT

public:
    explicit notes_window(QWidget *parent = nullptr);
    ~notes_window();
private:
    NoteGroup* selectedGroup;
    Note* selectedNote;
    void note_show(Note* note);
private slots:
    void on_AddGroup_Button_clicked();

    void on_Groups_listWidget_currentRowChanged(int currentRow);

    void on_Notes_listWidget_currentRowChanged(int currentRow);

    void on_Note_textEdit_textChanged();

    void on_Delete_Button_clicked();

    void on_Save_Button_clicked();

    void on_AddNote_Button_clicked();

    void on_Groups_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_Groups_comboBox_currentIndexChanged(int index);

    void on_DeleteGroup_pushButton_clicked();

private:
    Ui::notes_window *ui;
};

#endif // NOTES_WINDOW_H
