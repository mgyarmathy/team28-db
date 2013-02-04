/*
* Name        : Record.h
* Author      : Team 28
* Description : - header file for Record class
*/

#ifndef RECORD_H_
#define RECORD_H_

#include <string>
#include <iostream>

class Record{

	public:
		Record(int entryCount);
			
		string getEntry(int index);	
		void updateEntry(int index, string s);

	private:
		vector<string> tuple;
			
};

#endif //RECORD_H_
