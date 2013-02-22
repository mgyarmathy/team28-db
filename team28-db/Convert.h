#include "dbExceptions.h"
#include <string>

using namespace std;

#ifndef CONVERT_H_
#define CONVERT_H_

class __declspec(dllexport) Convert {
public:
	static int toInt(string s);
	static float toFloat(string s);
};

#endif
