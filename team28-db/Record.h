/*
* Name        : Record.h
* Author      : Team 28
* Description : - header file for Record class
*/

#ifndef RECORD_H_
#define RECORD_H_

#include <string>
#include <iostream>

class Record
{
	public:
		Record(int n);
			
		string getRecord();
			
		void setRecord(int n, string replace);

	private:
		vector<string> tuple;
		
	
};

#endif //RECORD_H_
