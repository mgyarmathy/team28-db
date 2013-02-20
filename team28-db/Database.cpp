#include "Database.h"
#include <iostream>
#include <fstream>

Database::Database() {}
Database::Database(const Database &d) {}
Database::Database(string fileName) {}
Database::Database(const Table &t) {}

int Database::addTable(const Table &t, string name) {
	tables.insert(pair<string, Table>(name, t));
	return 0;
}
int Database::dropTable(string name) {
	tables.erase(name);
	return 0;
}

int Database::save(string filename) {
	ofstream file;
	file.open(filename);
	vector<Table> tables_list = this->getTables();
	vector<string> tableNames = this->listTables();
	file << tables_list.size() << "\n";
	for(int i = 0; i<tables_list.size(); i++){
		file << tableNames[i] << "\n";
		vector<Attribute> columns = tables_list[i].getColumns();
		file << columns.size() << "\n";
		for(int i = 0; i<columns.size(); i++){
			file << columns[i].type << " " << columns[i].name << "\n";
		}

	}
	file.close();
	return 0;
}
int Database::load(string filename) {
	return 0;
}
int Database::merge(const Database& d) {
	return 0;
}
int Database::merge(string fileName) {
	return 0;
}
int Database::copy(const Database& d) {
	return 0;
}
int Database::copy(string fileName) {
	return 0;
}

vector<string> Database::listTables() {
	map<string, Table>::iterator it;
	vector<string> tableNames;
	for (it=tables.begin(); it!=tables.end(); it++){
		tableNames.push_back(it->first);
	}
	return tableNames;
}
vector<Table> Database::getTables() {
	map<string, Table>::iterator it;
	vector<Table> tbls;
	for (it=tables.begin(); it!=tables.end(); it++){
		tbls.push_back(it->second);
	}
	return tbls;
}

Table Database::queryTable(string columnsToSelect, string fromTable, string whereClause) {
	return Table();
}
int Database::deleteRows(string fromTable, string whereClause) {
	return 0;
}
int Database::updateTable(string tableName, string setClause, string whereClause) {
	return 0;
}
