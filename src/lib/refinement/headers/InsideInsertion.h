#ifndef INSIDEINSERTION_H
#define INSIDEINSERTION_H

#include <QPoint>
#include "InsertionMethod.h"
#include "Configuration.h"
#include "src/lib/geometric/headers/Triangle.h"
#include "src/lib/refinement/headers/QueueOfTrianglesToProcess.h"
#include "src/lib/refinement/headers/QueueOfEncroachedEdges.h"

class InsideInsertion: public InsertionMethod{
public:
    InsideInsertion(Configuration* conf, QueueOfTrianglesToProcess* qt, QueueOfEncroachedEdges* qe);
    virtual void execute() = 0;
    ~InsideInsertion();
protected:
    Configuration* confp;
    QueueOfTrianglesToProcess* qtp;
    QueueOfEncroachedEdges* qep;
};

#endif // INSIDEINSERTION_H
