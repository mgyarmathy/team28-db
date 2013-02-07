#include "Table.h"

Table::Table() {
}
Table::Table(vector<Attribute> columns) {
}

//column operations
int Table::addColumn(Attribute a) {
	return 0;
}
int Table::deleteColumn(Attribute a) {
	return 0;
}
int Table::deleteColumn(string attributeName) {
	return 0;
}
int Table::renameColumn(string oldName, string newName) {
	return 0;
}
vector<Attribute> Table::getColumns() {
	return vector<Attribute>();
}
		
//row operations
int Table::insertRow(string values) {
	return 0;
}
int Table::getNumberOfRows() {
	return 0;
}
Record& Table::rowAt(int index) {
	return Record();
}
		
//key operations
int Table::setKey(vector<Attribute> attributes) {
	return 0;
}
int Table::setKey(vector<string> attributes) {
	return 0;
}

//table join operations
Table Table::crossJoin(const Table& a, const Table& b) {
	return Table();
}
Table Table::naturalJoin(const Table& a, const Table& b) {
	return Table();
}

//table computation functions
string Table::sum(string column) {
	return string();
}

string Table::min(string column) {
	return string();
}

string Table::max(string column) {
	return string();
}

int Table::count(string column) {
	return 0;
}

