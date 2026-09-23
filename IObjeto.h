#pragma once
#include <string>
using namespace std;

class IObjeto {
public:
	virtual string toString() const = 0;
	virtual bool equals(IObjeto*) = 0;
	virtual string getType() const = 0;
};

