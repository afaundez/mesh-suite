#ifndef FACTORYINSERTIONMETHOD_H
#define FACTORYINSERTIONMETHOD_H

#include "InsertionMethod.h"
#include "Configuration.h"
#include "Options.h"
#include "src/lib/refinement/headers/QueueOfTrianglesToProcess.h"
#include "src/lib/refinement/headers/QueueOfEncroachedEdges.h"

class FactoryInsertionMethod{
public:
    static InsertionMethod* create(Configuration* c, QueueOfTrianglesToProcess* qt, QueueOfEncroachedEdges* qe, Options* o);
};

#endif // FACTORYINSERTIONMETHOD_H
