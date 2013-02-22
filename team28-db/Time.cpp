/*
* Name        : Time.cpp
* Author      : Nishaanth Narayanan
* Description : - cpp file for Time class
*				- contains implementations of time functions
*/

#include "Time.h"

//output stream override
ostream& operator<<(ostream& os, const Time& d) {
    return os << setw(2) << right << setfill('0') << d.hours() << ":"
            << setw(2) << right << setfill('0') << d.minutes() << ":"
            << d.seconds() << setfill(' ');
}

//input stream override
istream& operator>>(istream& is, Time& d){
	char slash1, slash2; // for the 2 ':'s
  	is >> d.h >> slash1 >> d.m >> slash2 >> d.s;
  	return is;
}
