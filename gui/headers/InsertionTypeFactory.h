#ifndef INSERTIONTYPEFACTORY_H
#define INSERTIONTYPEFACTORY_H

#include "InsertionType.h"

class InsertionTypeFactory
{
public:
    static InsertionType* build(int index);

};

#endif // INSERTIONTYPEFACTORY_H
