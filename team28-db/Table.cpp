#include "Table.h"

Table::Table() {
}
Table::Table(vector<Attribute> fields) {
	columns = fields;
	vector<bool> keys(columns.size(), false);
	isKey = keys;
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
		throw ColumnAlreadyExistsException();
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
/*int Table::insertRow(string values) {
	return 0;
}*/

int Table::insertRow(vector<string> values){
	if(values.size() == columns.size()){
		rows.push_back(Record(values));
	}
	else if(values.size() < columns.size()){
		while(values.size() != columns.size()){
			values.push_back(string());
		}
		rows.push_back(Record(values));

	}
	else{ //too many values, not enough columns
		throw RowTooLargeException();
		return 0;
	}
}

int Table::getNumberOfRows() {
	return rows.size();
}
Record& Table::rowAt(int index) {
	if(index >= rows.size())
		throw OutOfBoundsException();
	else return rows[index];
}
		
//key operations
int Table::setKey(vector<Attribute> attributes) {
	vector <bool> newKeys (columns.size(), false);
	//iterate through all specified attributes
	for(int i = 0; i<attributes.size(); i++){ 
		//find them in the list of columns
		for(int j = 0; j<columns.size(); j++){ 
			if(columns[j].name == attributes[i].name){
				newKeys[j] = true;
				break;
			}
		}
	}
	isKey = newKeys;
	return 0;
}
int Table::setKey(vector<string> attributes) {
	vector <bool> newKeys (columns.size(), false);
	//iterate through all specified attributes
	for(int i = 0; i<attributes.size(); i++){
		//find them in the list of columns
		for(int j = 0; j<columns.size(); j++){
			if(columns[j].name == attributes[i]){
				newKeys[j] = true;
				break;
			}
		}
	}
	isKey = newKeys;
	return 0;
}

//table join operations
Table Table::crossJoin(Table a, Table b) {
	Table t = a;

	return Table();
}
Table Table::naturalJoin(Table a, Table b) {
	return Table();
}

//table computation functions
string Table::sum(string columnName) {
	int n = -1; // finding the index of the column
	int isum = 0; // sum if integers
	float fsum = 0.0; // sum if floats

	for(int i = 0; i < columns.size(); i++) {
		if(columns[i].name == columnName) {
			n = 1;
			break;
		}
	}
	if(n == -1)	{
		throw ColumnNotFoundException();
		return string();
	}
	else {
		for(int i = 0; i < rows.size(); i++) {
			switch(columns[n].type) {
				case(0): { //type is integer
					isum += atoi((rows[i].elementAt(n)).c_str());
					break;
				}
				case (1) : { //type is float
					fsum += atof((rows[i].elementAt(n)).c_str());
					break;
				}
				case (2): // type is string
				case (3): // type is date
				case (4): // type is time
				default: {
					throw InvalidTypeForOperationException();
					break;
				}
			}

		}
	}
	if(columns[n].type == 0){
		return std::to_string(static_cast<long long>(isum));
	}
	else {
		return std::to_string(static_cast<long long>(fsum));
	}
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
