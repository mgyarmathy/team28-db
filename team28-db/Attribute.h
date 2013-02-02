/*
* Name        : Attribute.h
* Author      : Team 28
* Description : - header file for Attribute class
*/

#ifndef ATTRIBUTE_H_
#define ATTRIBUTE_H_

class Attribute
{
	private:
		enum attrType { INTEGER, FLOAT, VARSTRING, DATE, TIME };
		string attrName;
	
	public:
		/*NOTE: for the constructor, seeing as we used an enum, various ints describe various enums.
		  Whoever writes this, please cast the ints in a logical manner */
		Attribute( int n, string name);
		
		string getName():
		
		void setName(string name);

}

#endif //ATTRIBUE_H_