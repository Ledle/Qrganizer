#ifndef NOTEGROUP_H
#define NOTEGROUP_H
#include "group.h"
#include <QListWidget>
#include <QComboBox>
class Note;
class NoteGroup :public Group
{
private:
    static QList<NoteGroup*>* groups;
    QList<Note*>* notes;
    using Group::Events;
    using Group::getEvent;
    using Group::Add;
    using Group::Remove;
    using Group::ShowEvents;
public:
    NoteGroup();
    NoteGroup(QString name);
    QList<Note*> Notes();
    static QList<NoteGroup*> Groups();
    void Add(Note* note);
    void Remove(Note* note);
    static void Save();
    static void Load();
    static void Show(QListWidget* list, QComboBox* box);
    static NoteGroup* getGroup(int n);
    void ShowNotes(QListWidget* list);
    Note* getNote(int n);
    static void RemoveGroup(NoteGroup* group);
    friend QDataStream& operator>>(QDataStream& d, NoteGroup& g);
    friend QDataStream& operator<<(QDataStream& d, const NoteGroup& g);
};

#endif // NOTEGROUP_H
