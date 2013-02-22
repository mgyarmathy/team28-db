/*
* Name        : Database.h
* Author      : Team 28
* Description : - header file for Database class
*/

#ifndef DATABASE_H_
#define DATABASE_H_

#include "Table.h"
#include <map>

using namespace std;

class __declspec(dllexport) Database {

	public:
		Database();
		Database(Database &d); //copy constructor
		Database(string fileName); // Create a database from a file. Throws FileNotFoundException if file does not exist
		Database(const Table &t, string tableName); //create a database from a preexisting table

		int addTable(const Table &t, string name);
		int dropTable(string name);

		int save(string filename);
		int load(string filename);
		int merge(Database& d);
		int merge(string fileName);
		int copy(const Database& d);
		int copy(string fileName);

		vector<string> listTables();
		vector<Table> getTables();

		Table queryTable(string columnsToSelect, string fromTable, string whereClause);
		int deleteRows(string fromTable, string whereClause);
		int updateTable(string tableName, string setClause, string whereClause);

	private:
		void clearDatabase();
		bool tableNameExists(string name);
		map<string, Table> tables;
};

#endif //DATABASE_H_
