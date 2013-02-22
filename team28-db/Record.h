/*
* Name        : Record.h
* Author      : Team 28
* Description : - header file for Record class
*/

#ifndef RECORD_H_
#define RECORD_H_

#include <string>
#include <vector>
#include <cstring> // this was for c_str()
#include "Table.h"
#include "dbExceptions.h"

using namespace std;

class __declspec(dllexport) Record {
	friend class Table;
	public:
		Record();
		Record(vector<string> data);
			
		string& elementAt(int index);	// throws OutOfBoundsException

	private:
		vector<string> entries;
};

#endif //RECORD_H_
