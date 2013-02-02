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
		Record(int n)
		{
			for(int i = 0; i < n; i++)
			{
				cout<<"Enter another record\n";
				cin>>tuple[i];
			}
		}
		
		string getRecord(int n)
		{
			return tuple[n];
		}
		
		void setRecord(int n, string replace)
		{
			tuple[n] = replace;
		}
};

#endif //RECORD_H_