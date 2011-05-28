#ifndef FACTORYINSERTIONMETHOD_H
#define FACTORYINSERTIONMETHOD_H

#include "lib/refinement/insertion/InsertionMethod.h"
#include "lib/refinement/Configuration.h"
#include "lib/refinement/Options.h"

class FactoryInsertionMethod{
public:
    static InsertionMethod* create(Configuration* c, Options* o);
};

#endif // FACTORYINSERTIONMETHOD_H
