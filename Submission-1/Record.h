/*
* Name        : Record.h
* Author      : Team 28
* Description : - header file for Record class
*/

#ifndef RECORD_H_
#define RECORD_H_

#include <string>

using namespace std;

class Record {
	public:
		Record(vector<string> entries);
			
		string& elementAt(int index);
};

#endif //RECORD_H_
