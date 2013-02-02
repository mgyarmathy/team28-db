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
	private:
		vector<string> tuple;
		
	public:
		Record(int n);
			
		string getRecord(int n);
			
		void setRecord(int n, string replace);
};

#endif //RECORD_H_
