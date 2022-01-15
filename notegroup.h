#ifndef NOTEGROUP_H
#define NOTEGROUP_H
#include "group.h"

class Note;
class NoteGroup :public Group
{
private:
    static QList<NoteGroup*>* groups;
    QList<Note*>* notes;
public:
    NoteGroup();
    NoteGroup(QString name);
    QList<Note*> Notes();
    static QList<NoteGroup*> Groups();
    void Add(Note* note);
    void Remove(Note* note);
    static void Save();
    static void Load();
};

#endif // NOTEGROUP_H
