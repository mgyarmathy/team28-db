#include "Database.h"
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
	ofstream file(filename);	//do you not want to error check here ? highly plausible that incorrect filename
	vector<Table> tablesList = this->getTables();
	vector<string> tableNames = this->listTables();
	file << tablesList.size() << "\n";
	for(int i = 0; i<tablesList.size(); i++){
		file << tableNames[i] << "\n";
		vector<Attribute> columns = tablesList[i].getColumns();
		file << columns.size() << "\n";
		for(int j = 0; j<columns.size(); j++){
			file << columns[j].type << "\n" << columns[j].name << "\n";
		}
		for(int j = 0; j<tablesList[i].getNumberOfRows(); j++){
			Record r = tablesList[i].rowAt(j);
			//TODO: save contents of record
		}
	}
	file.close();
	return 0;
}
int Database::load(string filename) {
	ifstream file(filename);
	if(file){
		this->clearDatabase();
		int tableCount;
		file >> tableCount;
		cout << tableCount << " tables exist." << endl;
		for(int i = 0; i<tableCount; i++){
			Table t;
			string tableName;
			getline(file, tableName);
			int columnCount;
			file >> columnCount;
			for(int j = 0; j<columnCount; j++){ //add table columns
				int attributeTypeEnum;
				string attributeName;
				file >> attributeTypeEnum;
				getline(file, attributeName);
				Attribute a = Attribute(Type(attributeTypeEnum), attributeName);
				t.addColumn(a);
			}
			//TODO: insert records to table


			//once table formed, add to database
			this->addTable(t, tableName);
		}
	}
	else{
		throw FileNotFoundException();
		return 1;
	}
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

/* private helper functions */

void Database::clearDatabase(){
	map<string, Table> emptyTableMap;
	tables = emptyTableMap;
}
