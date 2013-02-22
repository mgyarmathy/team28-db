#include "Table.h"
#include "Date.h"
#include "Time.h"
#include "Convert.h"

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
		 //now that the attribute column is added, a "NULL" entry must be added to the end of each row
		for(int i=0; i < rows.size(); i++){
			rows[i].entries.push_back("NULL");
		}
		isKey.push_back(false);		// when you add a column, you also add an entry saying that it's not a key
		return 1;
	}
	else {
		return 0;
	}
}

int Table::deleteColumn(Attribute a) {
	//make sure the column exists
	if(columnExists(a.name)){
		for(int i = 0; i<columns.size(); i++){
			if(columns[i].name == a.name){
				//first the column entry is deleted
				columns.erase(columns.begin()+i);
				//next the key entry is deleted in the corresponding index
				isKey.erase(isKey.begin()+i);
				//and finally all the entries in the rows for that column are erased
				for(int j=0; j < rows.size(); j++){
					rows[j].entries.erase(rows[j].entries.begin()+i);
				}
			}
		}
		return 1;
	}
	else {
		return 0;
	}
}
int Table::deleteColumn(string attributeName) {
	//make sure the column exists
	if(columnExists(attributeName)){
		for(int i = 0; i<columns.size(); i++){
			if(columns[i].name == attributeName){
				//first the column entry is deleted
				columns.erase(columns.begin()+i);
				//next the key entry is deleted in the corresponding index
				isKey.erase(isKey.begin()+i);
				//and finally all the entries in the rows for that column are erased
				for(int j=0; j < rows.size(); j++){
					rows[j].entries.erase(rows[j].entries.begin()+i);
				}
			}
		}
		return 1;
	}
	else {
		return 0;
	}
}
int Table::renameColumn(string oldName, string newName) {
	if(columnExists(oldName)){
		//check if the column exists
		for(int i = 0; i<columns.size(); i++){
			if(columns[i].name == oldName){
				//find the column and replace the name with the new name
				columns[i].name = newName;
			}
		}
		return 1;
	}
	else {
		return 0;
	}
}
vector<Attribute> Table::getColumns() {
	return columns;
}
		
//row operations
int Table::insertRow(vector<string> values){
	if(values.size() == columns.size()){
		rows.push_back(Record(values));
		return 1;
	}
	else if(values.size() < columns.size()){
		while(values.size() != columns.size()){
			values.push_back("NULL");
		}
		rows.push_back(Record(values));
		return 1;
	}
	else{ //too many values, not enough columns
		return 0;
	}
}

int Table::getNumberOfRows() {
	return rows.size();
}

Record& Table::rowAt(int index) {
	if(index >= rows.size())
		throw OutOfBoundsException();
	//first check if the index exceeds the row count
	//then make sure that the index is a valid number
	else if(index < 0)
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

vector<Attribute> Table::getKeys(){
	vector<Attribute> keys;
	for(int i = 0; i<columns.size(); i++){
		if(isKey[i]) keys.push_back(columns[i]);
	}
	return keys;
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
	Table t;
	vector<Attribute> a_keys = a.getKeys();
	vector<Attribute> b_keys = b.getKeys();
	vector<Attribute> matching_keys;
	for(int i = 0; i<a_keys.size(); i++){
		for(int j = 0; j<b_keys.size(); j++){
			if(a_keys[i].name == b_keys[j].name){
				matching_keys.push_back(a_keys[i]);
			}
		}
	}
	if(matching_keys.size() > 0){
		vector<Attribute> a_columns = a.getColumns();
		vector<Attribute> b_columns = b.getColumns();
		for(int i = 0; i<a_columns.size(); i++){
			t.addColumn(a_columns[i]);
		}
		for(int i = 0; i<b_columns.size(); i++){
			t.addColumn(b_columns[i]); //duplicate columns handled in this function
		}
		for(int i = 0; i<a.getNumberOfRows(); i++){
			vector<string> entries;
			for(int j = 0; j<a.getColumns().size(); j++){
				entries.push_back(a.rowAt(i).elementAt(j));
			}
			string key_value = a.rowAt(i).elementAt(a.getKeyIndex(matching_keys[0].name)); //for now, just handle first matching key
			for(int j = 0; j<b.getNumberOfRows(); j++){
				if(key_value == b.rowAt(j).elementAt(b.getKeyIndex(matching_keys[0].name))){ //key_value matches row in table b
					for(int k = 0; k<b.getColumns().size(); k++){ //add all other contents of matching row
						if(k != b.getKeyIndex(matching_keys[0].name)){
							entries.push_back(b.rowAt(j).elementAt(k));
						}
					}
					break;
				}
			}
			//if matching rows are joined, add to the new table
			if(entries.size() != a.getColumns().size()){
				t.insertRow(entries);
			}
		}
		return t;
	}
	else{
		throw NoMatchingKeysException();
	}
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
					isum += Convert::toInt(rows[i].elementAt(n));
					break;
				}
				case (1) : { //type is float
					fsum += Convert::toFloat(rows[i].elementAt(n));
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
	int imin = 999999; // min if integers
	float fmin = 99999999.99; // min if floats
	long int daycount = 999999999; // number of days
	long int seccount = 999999999; // number of seconds
	Date dmin = Date();
	Time tmin = Time();

	

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
					if (imin > Convert::toInt(rows[i].elementAt(n)))
						imin = Convert::toInt(rows[i].elementAt(n));
					break;
				}
				case (1) : { //type is float
					if (fmin > Convert::toFloat(rows[i].elementAt(n)))
						fmin = Convert::toFloat(rows[i].elementAt(n));
					break;
				}
				case (2): { // type is string
					throw InvalidTypeForOperationException();
					break;
			    }
				case (3): {// type is date
					Date tempdate = Date(rows[i].elementAt(n));
					if(daycount > ((365*tempdate.year())+(30*tempdate.month())+tempdate.day())) {
						daycount = ((365*tempdate.year())+(30*tempdate.month())+tempdate.day());
						dmin = tempdate;
					}
					break;
			    }
				case (4): { // type is time
					Time temptime = Time(rows[i].elementAt(n));
					if(seccount > ((3600*temptime.hours())+(60*temptime.minutes())+temptime.seconds())) {
						seccount = ((3600*temptime.hours())+(60*temptime.minutes())+temptime.seconds());
						tmin = temptime;
					}
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
	long int daycount = 0; // number of days
	long int seccount = 0; // number of seconds
	Date dmax = Date();
	Time tmax = Time();

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
					if (imax < atoi((rows[i].elementAt(n)).c_str()))
						imax = atoi((rows[i].elementAt(n)).c_str());
					break;
				}
				case (1) : { //type is float
					if( fmax < atof((rows[i].elementAt(n)).c_str())) 
						fmax = atof((rows[i].elementAt(n)).c_str());
					break;
				}
				case (2): { // type is string
					throw InvalidTypeForOperationException();
					break;
			    }
				case (3): {// type is date
					Date tempdate = Date(rows[i].elementAt(n));
					if(daycount < ((365*tempdate.year())+(30*tempdate.month())+tempdate.day())) {
						daycount = ((365*tempdate.year())+(30*tempdate.month())+tempdate.day());
						dmax = tempdate;
					}
					break;
			    }
				case (4): { // type is time
					Time temptime = Time(rows[i].elementAt(n));
					if(seccount < ((3600*temptime.hours())+(60*temptime.minutes())+temptime.seconds())) {
						seccount = ((3600*temptime.hours())+(60*temptime.minutes())+temptime.seconds());
						tmax = temptime;
					}
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

int Table::getKeyIndex(string name){
	for(int i = 0; i<columns.size(); i++){
		if(name == columns[i].name) return i;
	}
	return -1;
}
