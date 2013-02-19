/*
* Name        : Record.h
* Author      : Team 28
* Description : - header file for Record class
*/

#ifndef RECORD_H_
#define RECORD_H_

#include <string>
#include <vector>

using namespace std;

class __declspec(dllexport) Record {
	public:
		Record();
		Record(vector<string> entries);
			
		string& elementAt(int index);
};

#endif //RECORD_H_
