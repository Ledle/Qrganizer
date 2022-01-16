#include "notes_window.h"
#include "ui_notes_window.h"

notes_window::notes_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::notes_window)
{
    ui->setupUi(this);
    ui->Note_textEdit->setReadOnly(true);
}

notes_window::~notes_window()
{
    delete ui;
}

void notes_window::on_AddGroup_Button_clicked()
{
    if (ui->GroupName_lineEdit->text() != "") {
        new NoteGroup(ui->GroupName_lineEdit->text());
    }
    selectedNote = NULL;
    ui->GroupName_lineEdit->setText("");
    NoteGroup::Show(ui->Groups_listWidget);
    ui->Groups_listWidget->setCurrentRow(ui->Groups_listWidget->count() - 1);
}


void notes_window::on_Groups_listWidget_currentRowChanged(int currentRow)
{
    NoteGroup* grp = NoteGroup::getGroup(currentRow);
    grp->ShowNotes(ui->Notes_listWidget);
    selectedGroup = grp;
    selectedNote = NULL;
    ui->Note_textEdit->clear();
    ui->Note_textEdit->setReadOnly(false);
    if (ui->Notes_listWidget->count() > 0) {
        ui->Notes_listWidget->setCurrentRow(0);
    }
}

void notes_window::note_show(Note* note) {
    selectedNote = note;
    ui->Note_textEdit->setPlainText(note->getText());
}

void notes_window::on_Notes_listWidget_currentRowChanged(int currentRow)
{
    Note* nt = (Note*)(selectedGroup->getNote(currentRow));
    if (nt != selectedNote) {
        note_show(nt);
    }
    else {
        if (ui->Note_groupBox->isHidden()) {
            ui->Note_groupBox->show();
        }
        else {
            ui->Note_groupBox->hide();
        }
    }
    ui->Note_groupBox->show();
    ui->Note_textEdit->setReadOnly(false);
}


void notes_window::on_Note_textEdit_textChanged()
{
    if (selectedNote != NULL) {
        selectedNote->setText(ui->Note_textEdit->toPlainText());
        selectedGroup->ShowNotes(ui->Notes_listWidget);
    }
}


void notes_window::on_Delete_Button_clicked()
{
    NoteGroup* grp = selectedNote->getGroup();
    grp->Remove(selectedNote);
    grp->ShowNotes(ui->Notes_listWidget);
}


void notes_window::on_Save_Button_clicked()
{
    //NoteGroup::Save();
}


void notes_window::on_AddNote_Button_clicked()
{
    if (ui->Note_textEdit->toPlainText() != "") {
        Note* nt = new Note(ui->Note_textEdit->toPlainText());
        selectedGroup->Add(nt);
        selectedGroup->ShowNotes(ui->Notes_listWidget);
    }
    ui->Notes_listWidget->setCurrentRow(ui->Notes_listWidget->count() - 1);
}