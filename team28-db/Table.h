/*
* Name        : Table.h
* Author      : Team 28
* Description : - header file for Table class
*/

#ifndef TABLE_H_
#define TABLE_H_

#include <vector>
#include <iostream>
#include "Attribute.h"
#include "Record.h"

using namespace std;

class __declspec(dllexport) Table {
	public:
		//constructors
		Table();
		Table(vector<Attribute> columns);

		//column operations
		int addColumn(Attribute a);
		int deleteColumn(Attribute a);
		int deleteColumn(string attributeName);
		int renameColumn(string oldName, string newName);
		vector<Attribute> getColumns();
		
		//row operations
		int insertRow(string values);
		int getNumberOfRows();
		Record& rowAt(int index);
		
		//key operations
		int setKey(Attribute a);
		int setKey(string attributeName);

		//table join operations
		Table crossJoin(const Table& a, const Table& b);
		Table naturalJoin(const Table& a, const Table& b);

		//table computation functions
		string sum(string column);
		string min(string column);
		string max(string column);
		int count(string column);

	private:
		bool columnExists(string name);
		vector<Attribute> columns;
		Attribute key;
};

#endif //TABLE_H_
