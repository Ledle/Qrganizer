#include "notegroup.h"
#include "note.h"

QList<NoteGroup*>* NoteGroup::groups = new QList<NoteGroup*>();
NoteGroup::NoteGroup() :Group()
{
	groups->push_back(this);
}
NoteGroup::NoteGroup(QString name):Group(name) {
	groups->push_back(this);
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
void NoteGroup::Save() {}
void NoteGroup::Load() {}