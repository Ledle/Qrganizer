#include "notegroup.h"
#include "note.h"


QList<NoteGroup*>* NoteGroup::groups = new QList<NoteGroup*>();
NoteGroup::NoteGroup() :Group()
{
	groups->push_back(this);
    notes = new QList<Note*>();
}
NoteGroup::NoteGroup(QString name):Group(name) {
	groups->push_back(this);
    notes = new QList<Note*>();
}
QList<Note*> NoteGroup::Notes() {
	return *notes;
}
QList<NoteGroup*> NoteGroup::Groups() {
	return *groups;
}
void NoteGroup::Add(Note* note) {
    if (!(notes->contains(note)))
    {
        notes->push_back(note);
        note->setGroup(this);
    }
}
void NoteGroup::Remove(Note* note) {
    for (auto i = notes->begin(); i != notes->end(); i++) {
        if (*i == note) {
            notes->erase(i);
            break;
        }
    }
}
void NoteGroup::Show(QListWidget* list) {
    for (int i = 0; i < list->count(); i++) {
        list->takeItem(i);
    }
    int n = 0;
    for (NoteGroup* g : *groups) {
        list->addItem(g->name);
        list->item(n++)->setData(1, n);
    }
}
NoteGroup* NoteGroup::getGroup(int n) {
    return groups->at(n);
}
void NoteGroup::ShowNotes(QListWidget* list) {
    for (int i = 0; i < list->count(); i++) {
        list->removeItemWidget(list->item(i));
    }
    int n = 0;
    QString st;
    if (!(notes->empty())) {
        for (Note* nt : *notes) {
            list->addItem(nt->getText());
        }
    }
}
Note* NoteGroup::getNote(int n) {
    return notes->at(n);
}
void NoteGroup::Save() {}
void NoteGroup::Load() {}