#pragma once
#include <functional>
#include "ObjectAdaptador.h"
#include "Lista.h"

class OpcionMenu : public ObjectAdaptador {
private:
	string titulo;
public:
	OpcionMenu(string);
	virtual ~OpcionMenu() = default;
	virtual string toString() const override;
};
