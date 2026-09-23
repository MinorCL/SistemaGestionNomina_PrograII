// ObjectAdaptador.h
#pragma once
#include "IObjeto.h"

class ObjectAdaptador : public IObjeto {
private:
public:

    string toString() const override;
    bool equals(IObjeto* ref) override;
    string getType() const override;

   
};

