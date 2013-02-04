/*
* Name        : Attribute.h
* Author      : Team 28
* Description : - header file for Attribute class
*/

#ifndef ATTRIBUTE_H_
#define ATTRIBUTE_H_

#include <string>

class Attribute
{
	enum type {INTEGER, FLOAT, VARSTRING, DATE, TIME};

	public:
		Attribute(type t, string name);
		
		string getName();
		void setName(string name);

	private:
		type t;
		string name;
	
}

#endif //ATTRIBUE_H_