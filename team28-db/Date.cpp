/*
* Name        : Date.cpp
* Author      : Michael Gyarmathy
* Description : - cpp file for Date class
*				- contains implementations of Date functions
*/

#include "Date.h"

//output stream override
ostream& operator<<(ostream& os, const Date& d) {
    return os << setw(2) << right << setfill('0') << d.month() << "/"
            << setw(2) << right << setfill('0') << d.day() << "/"
            << d.year() << setfill(' ');
}

//input stream override
istream& operator>>(istream& is, Date& d){
	char slash1, slash2;
  	is >> d.m >> slash1 >> d.d >> slash2 >> d.y;
  	return is;
}
