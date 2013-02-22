#include "Database.h"
#include <fstream>

// Default constructor, just make sures that the database is empty
Database::Database() {
	clearDatabase();
}

// Copy constructor. Copies all the entries form the given database into the new one
Database::Database(Database &d) {
	vector<Table> newTables = d.getTables();
	vector<string> newTableNames = d.listTables();
	clearDatabase();
	for(int i = 0; i < newTables.size(); i++) {
		tables.insert(pair<string, Table>(newTableNames[i], newTables[i]));
	}
}

// Constructor to create (load) database from a file
Database::Database(string filename) {
	if(load(filename) == 1) {
		throw FileNotFoundException();
	}
}

// Constructor to create a database from a table
Database::Database(const Table &t, string tableName) {
	clearDatabase();
	addTable(t, tableName);
}

// Add table to the database
int Database::addTable(const Table &t, string name) {
	if(!tableNameExists(name)){
		tables.insert(pair<string, Table>(name, t));
		return 1;
	}
	else{
		return 0;
	}
}

int Database::dropTable(string name) {
	if(!tableNameExists(name)){
		tables.erase(name);
		return 1;
	}
	else{
		return 0;
	}
}

int Database::save(string filename) {
	ofstream file(filename);
	if(file){
		vector<Table> tablesList = getTables();
		vector<string> tableNames = listTables();
		file << tablesList.size() << "\n";
		for(int i = 0; i<tablesList.size(); i++){
			file << tableNames[i] << "\n";
			vector<Attribute> columns = tablesList[i].getColumns();
			file << columns.size() << "\n";
			for(int j = 0; j<columns.size(); j++){
				file << columns[j].type << "\n" << columns[j].name << "\n";
			}
			file << tablesList[i].getNumberOfRows() << "\n";
			for(int j = 0; j<tablesList[i].getNumberOfRows(); j++){
				Record r = tablesList[i].rowAt(j);
				for(int k = 0; k<tablesList[i].getColumns().size(); k++){
					if(r.elementAt(k) != string()){
						file << r.elementAt(k) << "\n";
					}
					else{
						file << "NULL" << "\n";
					}
				}
			}
		}
		file.close();
		return 1;
	}
	else {
		return 0;
	}
}

int Database::load(string filename) {
	ifstream file(filename);
	if(file) {
		clearDatabase();
		int tableCount;
		file >> tableCount;
		for(int i = 0; i<tableCount; i++) {
			Table t;
			string tableName;
			getline(file, tableName);
			int columnCount;
			file >> columnCount;
			for(int j = 0; j<columnCount; j++) { //add table columns
				int attributeTypeEnum;
				string attributeName;
				file >> attributeTypeEnum;
				getline(file, attributeName);
				Attribute a = Attribute(Type(attributeTypeEnum), attributeName);
				t.addColumn(a);
			}
			int recordCount;
			file >> recordCount;
			for(int j = 0; j<recordCount; j++) {
				vector<string> entries;
				for(int k = 0; k<columnCount; k++) {
					string entry;
					getline(file, entry);
					if(entry != "NULL"){
						entries.push_back(entry);
					}
				}
				t.insertRow(entries);
			}
			//once table formed, add to database
			addTable(t, tableName);
		}
		return 1;
	}
	else {
		return 0;
	}	
}

int Database::merge(Database& d) {
	vector<Table> newTables = d.getTables();
	vector<string> newTableNames = d.listTables();
	for(int i = 0; i<newTables.size(); i++){
		tables.insert(pair<string, Table>(newTableNames[i], newTables[i]));
	}
	return 1;
}
int Database::merge(string filename) {
	ifstream file(filename);
	if(file){
		int tableCount;
		file >> tableCount;
		for(int i = 0; i<tableCount; i++) {
			Table t;
			string tableName;
			getline(file, tableName);
			int columnCount;
			file >> columnCount;
			for(int j = 0; j<columnCount; j++) { //add table columns
				int attributeTypeEnum;
				string attributeName;
				file >> attributeTypeEnum;
				getline(file, attributeName);
				Attribute a = Attribute(Type(attributeTypeEnum), attributeName);
				t.addColumn(a);
			}
			int recordCount;
			file >> recordCount;
			for(int j = 0; j<recordCount; j++) {
				vector<string> entries;
				for(int k = 0; k<columnCount; k++) {
					string entry;
					getline(file, entry);
					if(entry != "NULL") {
						entries.push_back(entry);
					}
				}
				t.insertRow(entries);
			}
			//once table formed, add to database
			addTable(t, tableName);
		}
		return 1;
	}
	else{
		return 0;
	}
	
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

Table Database::queryTable(vector<string> columnsToSelect, string fromTable, string whereClause) {
	// get the index of the table in the list if it exists
	int pos = -1;
	vector<string> tableNames = listTables();
	for(int i = 0; i < tableNames.size(); i++) {
		if(tableNames[i] == fromTable) {
			pos = i;
			break;
		}
	}
	if(pos == -1) {
		throw TableNotFoundException();
	}

	Table selectedTable = getTables()[pos];
	vector<Attribute> selectedColumns;

	// check what columns we need
	if(columnsToSelect.size() == 0) {
		selectedColumns = selectedTable.getColumns();
	}
	else {
		vector<Attribute> allColumns = selectedTable.getColumns();
		for(int i = 0; i < columnsToSelect.size(); i++) {
			for(int j = 0; j < allColumns.size(); j++) {
				if(columnsToSelect[i] == allColumns[j].name) {
					selectedColumns.push_back(allColumns[j]);
					break;
				}
			}
		}
	}

	// create an empty table with those columns
	Table generatedTable(selectedColumns);


	return Table();
}
int Database::deleteRows(string fromTable, string whereClause) {
	return 0;
}
int Database::updateTable(string tableName, string setClause, string whereClause) {
	return 0;
}

/* private helper functions */

void Database::clearDatabase() {
	tables.clear();
}

bool Database::tableNameExists(string name){
	vector<string> tableNames = listTables();
	for(int i = 0; i<tableNames.size(); i++){
		if(tableNames[i] == name) return true;
	}
	return false;
}
