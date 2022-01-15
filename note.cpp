#include "note.h"

Note::Note(){}
Note::Note(string text){
	this->text = text;
}
string Note::getText(){
	return text;
}
void Note::setText(string text){
	this->text = text;
}
NoteGroup* Note::getGroup(){
	return group;
}
void Note::setGroup(NoteGroup* group){
	this->group = group;
}