#include "Record.h"

Record::Record() {}

Record::Record(vector<string> entries) {
	this->entries = entries;
}
		
string& Record::elementAt(int index) {
	if(index >= entries.size()) return string();
	else return entries[index];
}
