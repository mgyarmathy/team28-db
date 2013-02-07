#include "Database.h"

Database::Database() {}
Database::Database(const Database &d) {}
Database::Database(string fileName) {}
Database::Database(const Table &t) {}

int Database::addTable(const Table &t, string name) {
	return 0;
}
int Database::dropTable(string name) {
	return 0;
}

int Database::save(string filename) {
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
	return vector<string>();
}
vector<Table> Database::getTables() {
	return vector<Table>();
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
