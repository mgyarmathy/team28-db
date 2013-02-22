#include "Attribute.h"
#include "dbExceptions.h"

Attribute::Attribute(Type t, string n) {
	//For an attribute to have a valid name
	//it needs to not contain: spaces, newlines, tabs, or symbols besides underscores.
	for(int i=0; i< n.length(); i++){
		if(  ('0'<=n[i]&&'9'>=n[i]) || ('A'<=n[i]&&'Z'>=n[i]) || ('a'<=n[i]&&'z'>=n[i])   ){
			type = t;
			name = n;
		}
		else{
			throw InvalidAttributeNameException();
		}
	}

}
