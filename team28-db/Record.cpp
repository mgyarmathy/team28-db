#include "Record.h"

Record::Record() {}

Record::Record(vector<string> data) {
	entries = data;
}
		
string& Record::elementAt(int index) {
	if(index >= entries.size())
		throw OutOfBoundsException();
	//initially check if the index is larger than the record size
	else if(index < 0)
	//then check that the index is a vlid number greater than 0
		throw OutOfBoundsException(); 
	else
		return entries[index];
}
