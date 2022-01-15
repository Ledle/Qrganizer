#include "notegroup.h"
#include "note.h"

list<NoteGroup*>* NoteGroup::groups = new list<NoteGroup*>();
NoteGroup::NoteGroup() :Group()
{
	groups->push_back(this);
}
NoteGroup::NoteGroup(string name):Group(name) {
	groups->push_back(this);
}
list<Note*> NoteGroup::Notes() {
	return *notes;
}
list<NoteGroup*> NoteGroup::Groups() {
	return *groups;
}
void NoteGroup::Add(Note* note) {
    bool contains = false;
    for (Note* nt : *(this->notes)) {
        if (note == nt) {
            contains = true;
        }
    }
    if (!contains)
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