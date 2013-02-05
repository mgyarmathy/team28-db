/*
* Name        : Table.h
* Author      : Team 28
* Description : - header file for Table class
*/

#ifndef TABLE_H_
#define TABLE_H_

#include <vector>
#include "Attribute.h"
#include "Record.h"

using namespace std;

class Table {
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
		int setKey(vector<Attribute> attributes);
		int setKey(vector<string> attributes);

		//table join operations
		Table crossJoin(const Table& a, const Table& b);
		Table naturalJoin(const Table& a, const Table& b);

		//table computation functions
		template <class T>
		T sum(string column);

		template <class T>
		T min(string column);

		template <class T>
		T max(string column);

		int count(string column);
};

#endif //TABLE_H_
