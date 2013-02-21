#include "Table.h"

Table::Table() {
}
Table::Table(vector<Attribute> fields) {
	columns = fields;
	for(int i=0;i<columns.size();i++) {	// make respective entries in isKey
		isKey.push_back(false);
	}
}

//column operations
int Table::addColumn(Attribute a) {
	//check to make sure column doesn't already exist
	if(!columnExists(a.name)){ 
		columns.push_back(a);
		isKey.push_back(false);		// when you add a column, you also add an entry saying that it's not a key
		return 1;
	}
	else {
		return 0;
	}
}
int Table::deleteColumn(Attribute a) {
	//remove that entry from the vector
	return 0;
}
int Table::deleteColumn(string attributeName) {
	//remove the entry from the vector
	return 0;
}
int Table::renameColumn(string oldName, string newName) {
	return 0;
}
vector<Attribute> Table::getColumns() {
	return columns;
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
	/*
	vector<Attribute> matching_keys;
	for(int i = 0; i<attributes.size(); i++){
		for(int j = 0; j<columns.size(); j++){
			if(columns[j].name == attributes[i].name){
				matching_keys.push_back(columns[j]);
				break;
			}
		}
	}
	key = matching_keys;
	*/

	// isKey is now a vector<bool> to just tell if the attribute at that index is a key
	return 0;
}
int Table::setKey(vector<string> attributes) {
	/*
	vector<Attribute> matching_keys;
	for(int i = 0; i<attributes.size(); i++){
		for(int j = 0; j<columns.size(); j++){
			if(columns[j].name == attributes[i]){
				matching_keys.push_back(columns[j]);
				break;
			}
		}
	}
	key = matching_keys;
	*/
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

/* private helper functions */
bool Table::columnExists(string name){
	for(int i = 0; i<columns.size(); i++){
		if(columns[i].name == name) return true;
	}
	return false;
}
