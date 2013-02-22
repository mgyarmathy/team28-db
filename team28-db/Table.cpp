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
	Table t;
	vector<Attribute> a_columns = a.getColumns();
	vector<Attribute> b_columns = b.getColumns();
	for(int i = 0; i<a_columns.size(); i++){
		t.addColumn(a_columns[i]);
	}
	for(int i = 0; i<b_columns.size(); i++){
		t.addColumn(b_columns[i]);
	}
	for(int i = 0; i<a.getNumberOfRows(); i++){
		for(int j = 0; j<b.getNumberOfRows(); j++){
			vector<string> entries;
			for(int k = 0; k<a_columns.size(); k++){//a entries
			entries.push_back(a.rowAt(i).elementAt(k));

			}
			for(int k = 0; k<b_columns.size(); k++){
				entries.push_back(b.rowAt(j).elementAt(k));
			}
			t.insertRow(entries);
		}
	}
	return t;
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

string Table::min(string columnName) {
	int n = -1; // finding the index of the column
	int imin = 0; // min if integers
	float fmin = 0.0; // min if floats

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
					if (imin < atoi((rows[i].elementAt(n)).c_str()))
						imin = atoi((rows[i].elementAt(n)).c_str());
					break;
				}
				case (1) : { //type is float
					if( fmin < atof((rows[i].elementAt(n)).c_str())) 
						fmin = atof((rows[i].elementAt(n)).c_str());
					break;
				}
				case (2): { // type is string
					throw InvalidTypeForOperationException();
					break;
			    }
				case (3): {// type is date
					break;
			    }
				case (4): { // type is time
					break;
				}
				default: {
					throw InvalidTypeForOperationException();
					break;
				}
			}

		}
	}
	if(columns[n].type == 0){
		return std::to_string(static_cast<long long>(imin));
	}
	else {
		return std::to_string(static_cast<long long>(fmin));
	}	
	return string();
}

string Table::max(string columnName) {
	int n = -1; // finding the index of the column
	int imax = 0; // min if integers
	float fmax = 0.0; // min if floats

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
					if (imax > atoi((rows[i].elementAt(n)).c_str()))
						imax = atoi((rows[i].elementAt(n)).c_str());
					break;
				}
				case (1) : { //type is float
					if( fmax > atof((rows[i].elementAt(n)).c_str())) 
						fmax = atof((rows[i].elementAt(n)).c_str());
					break;
				}
				case (2): { // type is string
					throw InvalidTypeForOperationException();
					break;
			    }
				case (3): {// type is date
					break;
			    }
				case (4): { // type is time
					break;
				}
				default: {
					throw InvalidTypeForOperationException();
					break;
				}
			}

		}
	}
	if(columns[n].type == 0){
		return std::to_string(static_cast<long long>(imax));
	}
	else {
		return std::to_string(static_cast<long long>(fmax));
	}	
	return string();
}

int Table::count(string columnName) {	// does not account for uniqueness of the entries
	int n = -1; // finding the index of the column
	int count = 0; // count of number of elements in the column

	for(int i = 0; i < columns.size(); i++) {
		if(columns[i].name == columnName) {
			n = 1;
			break;
		}
	}
	if(n == -1)	{
		throw ColumnNotFoundException();
		return -1;
	}
	else {
	//	for(int i = 0; i < rows.size(); i++) {
	//		switch(columns[n].type) {
	//			case(0): { //type is integer
	//				if (atoi((rows[i].elementAt(n)).c_str()))
	//					imax = atoi((rows[i].elementAt(n)).c_str());
	//				break;
	//			}
	//			case (1) : { //type is float
	//				if( fmax > atof((rows[i].elementAt(n)).c_str())) 
	//					fmax = atof((rows[i].elementAt(n)).c_str());
	//				break;
	//			}
	//			case (2): { // type is string
	//				throw InvalidTypeForOperationException();
	//				break;
	//		    }
	//			case (3): {// type is date
	//				break;
	//		    }
	//			case (4): { // type is time
	//				break;
	//			}
	//			default: {
	//				throw InvalidTypeForOperationException();
	//				break;
	//			}
	//		}

	//	}
		return rows.size(); // if the column exists, number of entries is simply the number of rows
	}

}

/* private helper functions */
bool Table::columnExists(string name){
	for(int i = 0; i<columns.size(); i++){
		if(columns[i].name == name) return true;
	}
	return false;
}
