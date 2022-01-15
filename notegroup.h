#ifndef NOTEGROUP_H
#define NOTEGROUP_H
#include "group.h"

class Note;
class NoteGroup :public Group
{
private:
    static list<NoteGroup*>* groups;
    list<Note*>* notes;
public:
    NoteGroup();
    NoteGroup(string name);
    list<Note*> Notes();
    static list<NoteGroup*> Groups();
    void Add(Note* note);
    void Remove(Note* note);
    static void Save();
    static void Load();
};

#endif // NOTEGROUP_H
