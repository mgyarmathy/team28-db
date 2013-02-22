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
	friend class Database;
	public:
		//constructors
		Table();
		Table(vector<Attribute> fields);

		//column operations
		int addColumn(Attribute a); //throws ColumnAlreadyExistsException
		int deleteColumn(Attribute a);
		int deleteColumn(string attributeName);
		int renameColumn(string oldName, string newName);
		vector<Attribute> getColumns();
		
		//row operations
		/*int insertRow(string values);*/ //how are we to implement this? below seems like a better implementation
		int insertRow(vector<string> values); //throws RowTooLargeException
		int getNumberOfRows();
		Record& rowAt(int index);
		
		//key operations
		int setKey(vector<Attribute> attributes);
		int setKey(vector<string> attributes);
		vector<Attribute> getKeys(); 

		//table join operations
		Table crossJoin(Table a, Table b);
		Table naturalJoin(Table a, Table b); //throws NoMatchingKeyException

		//table computation functions
		string sum(string column);
		string min(string column);
		string max(string column);
		int count(string column);

	private:
		bool columnExists(string name);
		int getKeyIndex(string name);
		int getColumnIndex(string name);
		vector<Attribute> columns;	// stores the headers/titles
		vector<Record> rows;			// stores all the data
		vector<bool> isKey;			// tells if the particular attribute is a key
};

#endif //TABLE_H_
