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

class Table
{
	public:
		Table();
		Table(vector<Attribute> fields);

		void addField(Attribute a);
		void deleteField(Attribute a);
		void addEntry(Record r);

		vector<Attribute> attributes();
		int size(); //or numberOfEntries()?
		//Record iterator
		void renameField(string oldName, string newName);
		void setKey(vector<string> attributes);

		Table crossJoin(Table a, Table b);
		Table naturalJoin(Table a, Table b);

		//should these return floating point numbers?
		int sum(string field);
		int count(string field);
		int min(string field);
		int max(string field);


	private:
		vector<Attribute> fields;
		vector<Record> entries;
}

#endif //TABLE_H_
