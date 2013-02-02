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

		void add_table(Table t, string name);
		void drop_table(string name);

		void save(string filename);
		void load(string filename);
		void merge(Database d);
		void copy(Database d);

		vector<string> list_tables();
		vector<Table> get_tables();

		//query
		//delete
		//update

	private:

};

#endif //DATABASE_H_