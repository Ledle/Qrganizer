#ifndef NOTE_H
#define NOTE_H
#include <string>

using namespace std;

class NoteGroup;
class Note
{
private:
    string text = "";
    NoteGroup* group;
public:
    Note();
    Note(string name);
    string getText();
    void setText(string text);
    NoteGroup* getGroup();
    void setGroup(NoteGroup* group);
};

#endif // NOTE_H