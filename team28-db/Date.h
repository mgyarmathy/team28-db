/*
* Name        : Date.h
* Author      : Michael Gyarmathy
* Description : - header file for Date class
*/

#ifndef DATE_H_
#define DATE_H_

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Date{

public:
    Date(): m(1), d(1), y(2000) {} //default constructor
    Date(int month, int day, int year): m(month), d(day), y(year) {}
	Date(string inputvalues){
		stringstream ss (stringstream::in | stringstream::out);
		ss<<inputvalues;
		char slash1,slash2;
		ss>>m>>slash1>>d>>slash2>>y;
	}

    //accessor functions
    int month() const { return m; }
    int day() const { return d; }
    int year() const { return y; }

    friend ostream& operator<<(ostream& os, const Date& d);
    friend istream& operator>>(istream& is, Date& d);
    
private:
    int m, d, y;
};



#endif //DATE_H_
