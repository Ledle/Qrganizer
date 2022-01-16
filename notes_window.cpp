#include "notes_window.h"
#include "ui_notes_window.h"

notes_window::notes_window(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::notes_window)
{
    ui->setupUi(this);
    ui->Note_textEdit->setReadOnly(true);
    NoteGroup::Load();
    NoteGroup::Show(ui->Groups_listWidget, ui->Groups_comboBox);
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
    NoteGroup::Show(ui->Groups_listWidget,ui->Groups_comboBox);
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
    ui->Groups_comboBox->blockSignals(true);
    ui->Groups_comboBox->clear();
    ui->Groups_comboBox->blockSignals(false);
    for (NoteGroup* g : NoteGroup::Groups()) {
        ui->Groups_comboBox->addItem(g->getName());
    }
    ui->Groups_comboBox->setCurrentIndex(currentRow);
}

void notes_window::note_show(Note* note) {
    int i = NoteGroup::Groups().indexOf(selectedGroup);
    ui->Groups_comboBox->setCurrentIndex(i);
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
    if (selectedNote != NULL) {
        NoteGroup* grp = selectedNote->getGroup();
        grp->Remove(selectedNote);
        grp->ShowNotes(ui->Notes_listWidget);
    }
}


void notes_window::on_Save_Button_clicked()
{
    NoteGroup::Save();
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

void notes_window::on_Groups_comboBox_currentIndexChanged(int index)
{
    NoteGroup* grp = NoteGroup::Groups().at(index);
    if (grp != selectedGroup && selectedNote != NULL) {
        selectedNote->setGroup(grp);
        selectedGroup->Remove(selectedNote);
        grp->Add(selectedNote);
        selectedGroup = grp;
        ui->Groups_listWidget->setCurrentRow(index);
        grp->ShowNotes(ui->Notes_listWidget);
        note_show(selectedNote);
    }
}


void notes_window::on_DeleteGroup_Button_clicked()
{
    if (selectedGroup != NULL && ui->Groups_listWidget->currentRow() != -1) {
        int i = ui->Groups_listWidget->currentRow();
        NoteGroup::RemoveGroup(NoteGroup::Groups().at(i));
        NoteGroup::Show(ui->Groups_listWidget, ui->Groups_comboBox);
        if (ui->Groups_listWidget->count() > 0) {
            ui->Groups_listWidget->setCurrentRow(0);
        }
        else {
            selectedGroup = NULL;
        }
    }
}