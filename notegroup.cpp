#include "notegroup.h"
#include "note.h"
#include <QFile>
#include <QDataStream>
#include "settings.h"

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
void NoteGroup::Show(QListWidget* list, QComboBox* box) {
    list->blockSignals(true);
    list->clear();
    list->blockSignals(false);
    box->blockSignals(true);
    box->clear();
    box->blockSignals(false);
    int n = 0;
    for (NoteGroup* g : *groups) {
        list->addItem(g->name);
        list->item(n++)->setData(1, n);
        box->addItem(g->name);
    }
}
NoteGroup* NoteGroup::getGroup(int n) {
    return groups->at(n);
}
void NoteGroup::ShowNotes(QListWidget* list) {
    list->blockSignals(true);
    list->clear();
    list->blockSignals(false);
    if (this != NULL) {
        int n = 0;
        QString st;
        if (!(notes->empty())) {
            for (Note* nt : *notes) {
                list->addItem(nt->getText());
            }
        }
    }
}
Note* NoteGroup::getNote(int n) {
    return notes->at(n);
}
void NoteGroup::RemoveGroup(NoteGroup* group) {
    groups->removeAt(groups->indexOf(group));
}
void NoteGroup::Save() {
    QFile file(Settings::Note);
    QDataStream stream(&file);
    file.open(QIODevice::WriteOnly);
    int n = groups->size();
    stream << n;
    for (int i = 0; i < groups->size(); i++) {
        stream << *(groups->at(i));
    }
    file.close();
}
void NoteGroup::Load() {
    QFile file(Settings::Note);
    QDataStream stream(&file);
    file.open(QIODevice::ReadOnly);
    int n;
    stream >> n;
    NoteGroup* grp;
    Note* nt;
    for (int i = 0; i < n; i++) {
        grp = new NoteGroup();
        stream >> *grp;
        for (Note* t : *(grp->notes)) {
            nt = (Note*)t;
            nt->setGroup(grp);
        }
    }
    file.close();
}
QDataStream& operator<<(QDataStream& d, const NoteGroup& g) {
    int n = g.notes->size();
    d << n;
    Note* t;
    for (int i = 0; i < g.notes->size(); i++) {
        t = (Note*)(g.notes->at(i));
        d << *t;
    }
    d << g.name;
    return d;
}
QDataStream& operator>>(QDataStream& d, NoteGroup& g) {
    int n;
    d >> n;
    Note t;
    for (int i = 0; i < n; i++) {
        d >> t;
        g.notes->push_back(new Note(t));
    }
    d >> g.name;
    return d;
}