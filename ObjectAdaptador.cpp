#include "ObjectAdaptador.h"
#include <typeinfo>


string ObjectAdaptador::toString() const {
	return typeid(*this).name();
}

bool ObjectAdaptador::equals(IObjeto* ref) {
	return this == ref;
}

string ObjectAdaptador::getType() const {
	return typeid(*this).name();
}

