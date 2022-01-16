#ifndef NOTE_H
#define NOTE_H
#include <string>
#include <QString>
using namespace std;

class NoteGroup;
class Note
{
private:
    QString text = "";
    NoteGroup* group;
public:
    Note();
    Note(QString name);
    QString getText();
    void setText(QString text);
    NoteGroup* getGroup();
    void setGroup(NoteGroup* group);
    friend QDataStream& operator<<(QDataStream& d, const Note& u);
    friend QDataStream& operator>>(QDataStream& d, Note& u);
};

#endif // NOTE_H