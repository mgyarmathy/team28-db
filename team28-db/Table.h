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
		Table();
		Table(vector<Attribute> columns);

		int addColumn(Attribute a);
		int deleteColumn(Attribute a);
		int deleteColumn(string attributeName);

		int renameColumn(string oldName, string newName);
		
		int insertRow(string values);
		
		vector<Attribute> getColumns();

		int getNumberOfRows();

		Record& rowAt(int index);
		
		int setKey(vector<Attribute> attributes);
		int setKey(vector<string> attributes);

		Table crossJoin(const Table& a, const Table& b);
		Table naturalJoin(const Table& a, const Table& b);

		template <class T>
		T sum(string column);

		template <class T>
		T min(string column);

		template <class T>
		T max(string column);

		int count(string column);
};

#endif //TABLE_H_
