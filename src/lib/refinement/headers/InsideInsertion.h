#ifndef INSIDEINSERTION_H
#define INSIDEINSERTION_H

#include <QPoint>
#include "InsertionMethod.h"
#include "Configuration.h"
#include "src/lib/geometric/headers/Triangle.h"
#include "src/lib/refinement/headers/QueueOfTrianglesToProcess.h"

class InsideInsertion: public InsertionMethod{
public:
    InsideInsertion(Configuration* conf, QueueOfTrianglesToProcess* qt);
    virtual void execute() = 0;
    ~InsideInsertion();
protected:
    Configuration* confp;
    QueueOfTrianglesToProcess* qtp;
};

#endif // INSIDEINSERTION_H
