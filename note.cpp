#include "note.h"

Note::Note(){}
Note::Note(QString text){
	this->text = text;
}
QString Note::getText(){
	return text;
}
void Note::setText(QString text){
	this->text = text;
}
NoteGroup* Note::getGroup(){
	return group;
}
void Note::setGroup(NoteGroup* group){
	this->group = group;
}
QDataStream& operator<<(QDataStream& d, const Note& u) {
	d << u.text;
	return d;
}
QDataStream& operator>>(QDataStream& d, Note& u) {
	d >> u.text;
	return d;
}