#ifndef FACTORYINSERTIONMETHOD_H
#define FACTORYINSERTIONMETHOD_H

#include "InsertionMethod.h"
#include "Configuration.h"
#include "Options.h"

class FactoryInsertionMethod{
public:
    static InsertionMethod* create(Configuration* c, Options* o);
};

#endif // FACTORYINSERTIONMETHOD_H
