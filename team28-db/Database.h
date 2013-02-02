/*
* Name        : Database.h
* Author      : Team 28
* Description : - header file for Database class
*/

#ifndef DATABASE_H_
#define DATABASE_H_

#include <string>
#include <vector>
#include "Table.h"

using namespace std;

class Database
{
	public:
		Database() {};

		void addTable(Table t, string name);
		void dropTable(string name);

		void save(string filename);
		void load(string filename);
		void merge(Database d);
		void copy(Database d);

		vector<string> listTables();
		vector<Table> getTables();

		Table queryTable(string selectAttributes, string fromTable, string whereClause);
		void deleteRecord(string selectAttributes, string fromTable, string whereClause);
		void updateTable(string tableName, string whereClause, string setClause);

	private:
		vector<Table*> tables;

};

#endif //DATABASE_H_
