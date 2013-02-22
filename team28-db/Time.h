/*
* Name        : Time.h
* Author      : Nishaanth Narayanan
* Description : - header file for Date class
*/

#ifndef TIME_H_
#define TIME_H_

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Time{

public:
    Time(): h(12), m(0), s(0) {} //default constructor
    Time(int hours, int minutes, int seconds): h(hours), m(minutes), s(seconds) {}
	Time(string inputvalues){
		stringstream ss (stringstream::in | stringstream::out);
		ss<<inputvalues;
		char colon1,colon2;
		ss>>h>>colon1>>m>>colon2>>s;
	}

    //accessor functions
    int hours() const { return h; }
    int minutes() const { return m; }
    int seconds() const { return s; }

    friend ostream& operator<<(ostream& os, const Time& d);
    friend istream& operator>>(istream& is, Time& d);
    
private:
    int h, m, s;
};



#endif //TIME_H_
