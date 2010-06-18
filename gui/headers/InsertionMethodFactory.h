#ifndef INSERTIONMETHODFACTORY_H
#define INSERTIONMETHODFACTORY_H

#include "InsertionMethod.h"
#include "Constant.h"

class InsertionMethodFactory
{
public:
    static InsertionMethod* build(Constant::InsertionCase type, int index);

};

#endif // INSERTIONMETHODFACTORY_H
