#include "Convert.h"
#include <sstream>

int Convert::toInt(string s) {
	if(s == "NULL") {
		throw IsNullException();
	}
	else {
		int value = atoi(s.c_str());
		if(value == 0 && s!= "0")
			throw IsInvalidException();
		else
			return value;
	}
}

float Convert::toFloat(string s) {
	if(s == "NULL") {
		throw IsNullException();
	}
	else {
		int value = atof(s.c_str());
		if(value == 0.0 && s!= "0" && s!= "0.0")
			throw IsInvalidException();
		else
			return value;
	}
}

template <class T>
string Convert::toString(T x) {
	stringstream stream;
	stream<<x;
	string s;
	stream>>s;
	return s;
}
