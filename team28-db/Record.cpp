#include "Record.h"

Record::Record() {}

Record::Record(vector<string> data) {
	entries = data;
}
		
string& Record::elementAt(int index) {
	if(index >= entries.size())
		throw OutOfBoundsException();
	else return entries[index];
}
