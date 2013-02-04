/*
* Name        : Attribute.h
* Author      : Team 28
* Description : - header file for Attribute class
*/

#ifndef ATTRIBUTE_H_
#define ATTRIBUTE_H_

#include <string>

using namespace std;

enum Type {INTEGER, FLOAT, VARSTRING, DATE, TIME};

struct Attribute {
		Type type;
		string name;

		Attribute(Type t, string name);
};

#endif //ATTRIBUE_H_
